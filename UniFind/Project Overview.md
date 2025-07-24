### Project Objective
UniFind is an online platform designed as a Lost and Found Management System specifically for the students and staff of Northern University of Business and Technology Khulna. Its primary goal is to provide a centralized and efficient way for users to report items they have lost and to return items they have found to their rightful owners, minimizing the stress and inconvenience associated with losing personal belongings.

### Key Functionalities
The project offers distinct functionalities for two types of users: general users and administrators.

#### For General Users:
* **Registration and Login:** Users can create a new account with their details, including name, email, phone number, and department (`signup.php`), and subsequently log in with their credentials (`login.php`).
* **Report Lost Items:** Users can submit a report for a lost item, providing a title, category, date of loss, location, a detailed description, and an image (`report_lost.php`).
* **Report Found Items:** Similarly, users can report items they have found on campus, including all relevant details (`report_found.php`).
* **Search for Items:** Users can browse and search for lost or found items using various filters like item type, category, department, and date (`search.php`).
* **Profile Management:** Users have the ability to view and update their personal profile information (`profile.php`).
* **Manage Reports:** Users can view and manage all the items they have reported (`my_reports.php`).
* **Automatic Matching:** When a user reports a lost item, the system automatically suggests potential matches from the database of found items, based on category, date, and location.

#### For Administrators:
* **Dashboard:** Admins have access to a dashboard that displays key statistics, such as the total number of users, lost, found, and matched items (`admin/dashboard.php`).
* **User Management:** Admins can view a list of all users, edit their information, grant or revoke admin access, and delete user accounts (`admin/manage_users.php`, `admin/edit_user.php`).
* **Item Management:** Admins can oversee all lost and found items, edit their details, update their status (e.g., active, matched, returned), and delete reports (`admin/manage_items.php`).
* **Category and Department Management:** Admins are able to add, edit, or remove item categories and university departments (`admin/manage_categories.php`, `admin/manage_departments.php`).
* **Match Management:** Admins can review, confirm, or reject potential matches between lost and found items that have been flagged by users (`admin/manage_matches.php`, `admin/review_match.php`).

### Technology Stack
The project is built using the following technologies:
* **PHP:** Used for all backend logic and server-side operations.
* **MySQL:** Serves as the database to store all user data, item reports, and other relevant information (`unifind_db.sql`).
* **HTML/CSS:** Used for the structure and styling of the website (`assets/css/style.css`, `admin/assets/css/admin.css`).
* **JavaScript (with jQuery):** Implemented for client-side interactivity and to improve user experience (`assets/js/script.js`).

### How It Works
1.  **Database Connection:** The `includes/db.php` file establishes a connection to the MySQL database.
2.  **User Authentication:** The `includes/auth.php` file handles user registration, login, logout, and session management.
3.  **Core Functions:** The `includes/functions.php` file contains common functions used throughout the project, such as image uploading, date formatting, and item searching.
4.  **Frontend Interface:** Users interact with the website through various files like `index.php`, `search.php`, and the item detail pages (`lost_item.php`, `found_item.php`).
5.  **Admin Panel:** The files within the `admin` directory provide a secure and separate interface for administrators to manage the platform's content and users.

Overall, UniFind is a well-structured and practical web application designed to solve a common problem within an academic institution.