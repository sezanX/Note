### **1. Directory and File Structure**

The project is organized into a logical structure that separates user-facing pages, administrative pages, and core logic.

* `/` (Root Directory): Contains all the main pages that users interact with, such as `index.php`, `login.php`, `search.php`, and item reporting pages.
* `/includes/`: This is the heart of the application, containing the core PHP logic.
    * `db.php`: Handles the database connection.
    * `auth.php`: Manages user authentication (registration, login, sessions).
    * `functions.php`: Contains most of the application's reusable functions.
* `/admin/`: This directory holds the entire administrative panel, which is a separate, protected area for managing the site.
    * `/admin/includes/`: Contains header and footer files specific to the admin panel.
* `/assets/`: Stores static files like CSS, JavaScript, and images.
* `/uploads/`: This directory is where user-uploaded images for lost and found items are stored.

---
### **2. The Core `includes` Directory**

This directory contains the three most critical files that power the entire application.

* **`db.php`:**
    * **Purpose:** Its sole responsibility is to establish a connection to the MySQL database.
    * **How it works:** It defines constants for the database host, username, password, and name. It then creates a new `mysqli` object to connect to the database. This file is included at the beginning of almost every other PHP file that needs database access.

* **`auth.php`:**
    * **Purpose:** This file manages everything related to user accounts and sessions.
    * **Key Functions:**
        * `registerUser()`: Takes user data from the signup form, validates it, checks for existing users, hashes the password using `password_hash()`, and inserts the new user into the `users` table.
        * `loginUser()`: Takes a username and password, fetches the user from the database, and uses `password_verify()` to check if the password is correct. If it is, it starts a session and stores user information (`user_id`, `username`, `role`, etc.) in the `$_SESSION` global variable.
        * `isLoggedIn()`: A simple function that checks if `$_SESSION['logged_in']` is set to `true`, allowing you to protect pages.
        * `isAdmin()`: Checks if the logged-in user has the 'admin' role, used to restrict access to the admin panel.
        * `getCurrentUser()`: Fetches the complete profile of the currently logged-in user from the database.

* **`functions.php`:**
    * **Purpose:** This is a large, multi-purpose file containing most of the application's business logic.
    * **Key Functions:**
        * `uploadImage()`: Handles file uploads. It validates the file for errors, checks the type and size, creates a unique filename, and moves the uploaded file to the `/uploads/` directory.
        * `getCategories()`, `getDepartments()`: These functions query the database to fetch lists of all available categories and departments for use in forms and filters.
        * `getItemStats()`, `getStatistics()`: These retrieve various statistics, like the number of items lost today or the total number of users, for display on the homepage and admin dashboard.
        * `searchItems()`: A crucial function that builds a dynamic SQL query based on the filters provided by the user in `search.php`. It handles filtering by keyword, category, date range, and item type.
        * `findPotentialMatches()`, `findPotentialMatchesForFound()`: These implement the automatic matching feature. They search for items in the opposing category (e.g., searching "found" items when a "lost" item is reported) that have a similar category, a close date, and a matching location.
        * `createMatch()`: Inserts a new record into the `matches` table when a user claims an item, linking a lost and a found item together.

---
### **3. Authentication and Session Flow**

1.  A user visits `signup.php` and fills out the form. The data is sent to the `registerUser()` function in `auth.php`.
2.  After successful registration, the user is redirected to `login.php`.
3.  The user enters their credentials, which are passed to the `loginUser()` function.
4.  If the login is successful, `loginUser()` sets `$_SESSION` variables. The `session_start()` command at the top of `auth.php` ensures this session persists across pages.
5.  On pages that require a login (like `report_lost.php`), a check like `if (!isLoggedIn())` redirects unauthenticated users to the login page.
6.  If the user's role is 'admin', they can access the `/admin` directory. The `index.php` and header file inside `/admin` use the `isAdmin()` function to block access to non-admins.

---
### **4. Frontend Pages (How they work)**

* **`index.php`:** The homepage. It calls functions from `functions.php` like `getItemStats()` and `getRecentActivity()` to fetch and display dynamic content like statistics and recently reported items.
* **`report_lost.php` & `report_found.php`:** These are form-based pages. When a user submits the form:
    1.  The page validates the input.
    2.  If an image was uploaded, it calls the `uploadImage()` function.
    3.  It then prepares and executes an SQL `INSERT` statement to save the item details into either the `lost_items` or `found_items` table.
    4.  After successfully inserting, it calls `findPotentialMatches()` to check for matches and display them to the user.
* **`lost_item.php` & `found_item.php`:** These are detail pages. They get an item `id` from the URL (`$_GET['id']`), fetch all details for that specific item from the database using an SQL `SELECT` query with `JOIN`s to get category and user names, and then display the information. They also show potential matches if the item's status is 'active'.
* **`search.php`:** This page displays a form with various filters. When the form is submitted, the filter values are passed as URL parameters (`$_GET`). The page then calls the `searchItems()` function with these filters, which returns an array of matching items that are then displayed.

---
### **5. The Admin Panel (`/admin`)**

The admin panel is a self-contained section for site management.

* **Access Control:** Every page in this directory includes `admin/includes/admin_header.php`, which runs the `isAdmin()` check to ensure only administrators can view the page.
* **`dashboard.php`:** The admin landing page. It uses various SQL `COUNT` queries to fetch and display high-level statistics about the site's usage.
* **Management Pages (`manage_users.php`, `manage_items.php`, etc.):** These pages follow a similar pattern:
    1.  They handle actions passed via URL parameters (e.g., `?delete=123`). This includes `DELETE` or `UPDATE` SQL operations.
    2.  They fetch a list of all relevant records from the database (e.g., all users or all lost items), often with pagination.
    3.  They display the data in an HTML table, with links for actions like "Edit" and "Delete."
    4.  Many of these pages also include a search/filter form to help admins find specific records.