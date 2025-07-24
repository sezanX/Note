\### \*\*Contents\*\*



\*\*1. Problem Statement\*\*



Managing lost and found items within a large, bustling environment like a university campus is a significant challenge. Students, faculty, and staff who lose personal belongings often face a stressful, inefficient, and uncertain process in trying to recover them. There is typically no centralized system to report lost items or to hand in found ones, leading to items remaining unclaimed and owners never being reunited with their property. This creates inconvenience and a sense of insecurity within the campus community.



\*\*2. Objective of the Research\*\*



The primary objective of the UniFind project is to develop a centralized, efficient, and user-friendly Lost and Found Management System for Northern University of Business and Technology Khulna.



The specific goals are:

\* To create a single, accessible online platform for reporting both lost and found items.

\* To simplify the process of reuniting lost items with their rightful owners.

\* To implement an intelligent matching system that automatically suggests potential matches between lost and found item reports based on details like category, location, and date.

\* To provide a secure administrative backend for managing users, items, categories, and confirming matches to ensure the system's integrity.

\* To foster a more secure, supportive, and helpful community spirit within the university.



\*\*3. History and Background\*\*



This project is specifically tailored for the Northern University of Business and Technology Khulna community. The background for its development stems from the common and persistent issue of personal belongings being misplaced on campus. Without a formal system, the recovery of such items depends on chance or the goodwill of individuals, which is often unreliable. UniFind was conceived as a technological solution to bring structure and efficiency to this process, leveraging web technology to connect the campus community and facilitate the return of lost property.



\*\*4. Approach/Methodology\*\*



The project is a web-based application developed with a client-server architecture. The methodology involves two main components: a user-facing front-end and a secure administrative back-end.



\* \*\*Technology Stack\*\*:

&nbsp;   \* \*\*Backend\*\*: The server-side logic is built using \*\*PHP\*\*. This includes handling user authentication, database interactions, and the core business logic of the application.

&nbsp;   \* \*\*Database\*\*: A \*\*MySQL\*\* database is used to store all persistent data, including user profiles, lost and found item reports, categories, departments, and match records. The database schema is defined in the `unifind\_db.sql` file.

&nbsp;   \* \*\*Frontend\*\*: The user interface is created with \*\*HTML\*\*, styled with \*\*CSS\*\* (including the Bootstrap framework), and made interactive with \*\*JavaScript\*\* and \*\*jQuery\*\*.



\* \*\*System Architecture\*\*:

&nbsp;   \* \*\*Modular Codebase\*\*: The code is organized into modules. `includes/db.php` handles the database connection, `includes/auth.php` manages sessions and authentication, and `includes/functions.php` contains reusable functions for tasks like image uploads and data retrieval.

&nbsp;   \* \*\*User and Admin Roles\*\*: The system enforces role-based access control. Regular users can access the public-facing site to report and search for items, while users with an 'admin' role can access a separate administrative dashboard (`/admin`) to manage the entire system.



\*\*5. Requirements\*\*



\* \*\*Functional Requirements:\*\*

&nbsp;   \* \*\*User Account Management\*\*: Users must be able to register, log in, log out, and edit their own profiles.

&nbsp;   \* \*\*Item Reporting\*\*: Users must be able to submit detailed reports for both lost and found items, including uploading images.

&nbsp;   \* \*\*Item Searching\*\*: A search functionality with filters (category, department, date, keyword) must be available for all users.

&nbsp;   \* \*\*Automatic Matching\*\*: The system shall automatically suggest potential matches to users after they submit a report.

&nbsp;   \* \*\*Admin Dashboard\*\*: Administrators must have a dashboard with statistics and quick access to management functions.

&nbsp;   \* \*\*Admin Management\*\*: Admins must be able to perform CRUD (Create, Read, Update, Delete) operations on users, items, categories, and departments.



\* \*\*Non-Functional Requirements:\*\*

&nbsp;   \* \*\*Usability\*\*: The interface should be intuitive and easy to navigate for non-technical users.

&nbsp;   \* \*\*Security\*\*: The system must secure user data, especially passwords (which are hashed) and personal contact information. It must prevent unauthorized access to the admin panel.

&nbsp;   \* \*\*Performance\*\*: The system should handle requests and database queries efficiently to provide a responsive user experience.

&nbsp;   \* \*\*Reliability\*\*: The application should function correctly and consistently.



\*\*6. Progression Timeline\*\*



The provided project files do not contain information regarding the development timeline, such as start dates, milestones, or completion dates.



\*\*7. References\*\*



All information in this report is derived from the source code and documentation files of the UniFind project itself. Key files referenced include:

\* `about.php`

\* `index.php`

\* `lost\_item.php`, `report\_lost.php`

\* `found\_item.php`, `report\_found.php`

\* `search.php`

\* `profile.php`

\* `my\_reports.php`

\* `signup.php`, `login.php`

\* `includes/auth.php`, `includes/db.php`, `includes/functions.php`

\* `unifind\_db.sql`

\* All files within the `/admin` directory.

