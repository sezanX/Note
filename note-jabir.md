We will primarily use XML layout files to define the structure and appearance, and touch upon necessary Java/Kotlin concepts for list handling (RecyclerView).

**Prerequisites:**

1.  Android Studio installed.
2.  Basic understanding of Android development (Activities, Layouts, XML).
3.  A new Android Studio project created (choose "Empty Activity").

**Key Layout Components We'll Use:**

*   `ScrollView`: To make the entire content scrollable vertically.
*   `LinearLayout`: To arrange major sections vertically.
*   `ConstraintLayout`: Useful for arranging elements within sections (like the header or banner) with more flexibility.
*   `CardView`: To give rounded corners and elevation (shadows) to elements like the banner, search bar, and list items.
*   `RecyclerView`: The standard way to display lists of items efficiently (Categories, Recommended, Restaurants).
*   `ImageView`, `TextView`, `Button`, `EditText`.
*   `BottomNavigationView`: For the navigation bar at the bottom.

**Step-by-Step Guide:**

**Step 1: Project Setup and Dependencies**

1.  Create a new Android Studio project.
2.  Open your `build.gradle (app)` file.
3.  Add the following dependencies inside the `dependencies` block. These are for Material Design components, CardView, and RecyclerView:

    ```gradle
    dependencies {
        // ... other dependencies

        // Material Design (includes CardView, BottomNavigationView, etc.)
        implementation 'com.google.android.material:material:1.10.0' // Use the latest version available

        // RecyclerView
        implementation 'androidx.recyclerview:recyclerview:1.3.2' // Use the latest version available

        // Optional: Image loading library (like Coil or Glide) is highly recommended for real apps
        // implementation("io.coil-kt:coil:2.5.0") // For Kotlin projects
        // implementation 'com.github.bumptech.glide:glide:4.16.0' // For Java or Kotlin
        // annotationProcessor 'com.github.bumptech.glide:compiler:4.16.0' // For Glide

        // If you use Kotlin, add:
        implementation("androidx.core:core-ktx:1.12.0")
        implementation("androidx.appcompat:appcompat:1.6.1")
        implementation("com.google.android.material:material:1.10.0")
        implementation("androidx.constraintlayout:constraintlayout:2.1.4")
        testImplementation("junit:junit:4.13.2")
        androidTestImplementation("androidx.test.ext:junit:1.1.5")
        androidTestImplementation("androidx.test.espresso:espresso-core:3.5.1")
    }
    ```
4.  Sync your project after adding dependencies (`File -> Sync Project with Gradle Files`).

**Step 2: Main Layout Structure (`activity_main.xml`)**

This will be the main container for all sections.

1.  Open `res/layout/activity_main.xml`.
2.  Change the root layout to `CoordinatorLayout` if you plan to use the `BottomNavigationView` pinned to the bottom, otherwise, a simple `LinearLayout` or `ConstraintLayout` is fine, and we can add the `BottomNavigationView` outside the `ScrollView`. Let's use a `ConstraintLayout` for the root to easily place the `ScrollView` and `BottomNavigationView`.
3.  Add a `ScrollView` that contains a vertical `LinearLayout`. All your screen content (header, banner, search, lists) will go inside this `LinearLayout`.
4.  Add the `BottomNavigationView` outside the `ScrollView`, constrained to the bottom.

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="match_parent"
    android:background="@color/grey_light" > <!-- Define grey_light in colors.xml -->

    <ScrollView
        android:id="@+id/scrollView"
        android:layout_width="0dp"
        android:layout_height="0dp"
        app:layout_constraintTop_toTopOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintBottom_toTopOf="@+id/bottom_navigation">

        <LinearLayout
            android:layout_width="match_parent"
            android:layout_height="wrap_content"
            android:orientation="vertical"
            android:paddingBottom="16dp"> <!-- Add padding at the bottom to avoid content being hidden behind bottom nav -->

            <!-- Include or add layout for each section here -->

            <!-- 1. Header (Layout will be created next) -->
            <include layout="@layout/layout_header" />

            <!-- 2. Banner/Offer (Layout will be created) -->
            <include layout="@layout/layout_banner"
                android:layout_width="match_parent"
                android:layout_height="wrap_content"
                android:layout_marginTop="16dp"
                android:layout_marginStart="16dp"
                android:layout_marginEnd="16dp"/>

            <!-- 3. Search Bar (Layout will be created) -->
            <include layout="@layout/layout_search"
                android:layout_width="match_parent"
                android:layout_height="wrap_content"
                android:layout_marginTop="24dp"
                android:layout_marginStart="16dp"
                android:layout_marginEnd="16dp"/>

            <!-- 4. Categories Section (Layout will be created) -->
            <include layout="@layout/layout_section_header"
                android:layout_width="match_parent"
                android:layout_height="wrap_content"
                android:layout_marginTop="24dp"
                android:layout_marginStart="16dp"
                android:layout_marginEnd="16dp"
                app:layout_constraintTitleText="Catergories" /> <!-- Pass title text -->
            <androidx.recyclerview.widget.RecyclerView
                android:id="@+id/recycler_categories"
                android:layout_width="match_parent"
                android:layout_height="wrap_content"
                android:layout_marginTop="8dp"
                android:clipToPadding="false"
                android:paddingStart="16dp"
                android:paddingEnd="16dp"
                android:orientation="horizontal"
                app:layoutManager="androidx.recyclerview.widget.LinearLayoutManager"
                tools:listitem="@layout/item_category"
                tools:itemCount="5"/>

            <!-- 5. Recommended Section (Layout will be created) -->
            <include layout="@layout/layout_section_header"
                android:layout_width="match_parent"
                android:layout_height="wrap_content"
                android:layout_marginTop="24dp"
                android:layout_marginStart="16dp"
                android:layout_marginEnd="16dp"
                app:layout_constraintTitleText="Recommended" /> <!-- Pass title text -->
            <androidx.recyclerview.widget.RecyclerView
                android:id="@+id/recycler_recommended"
                android:layout_width="match_parent"
                android:layout_height="wrap_content"
                android:layout_marginTop="8dp"
                android:clipToPadding="false"
                android:paddingStart="16dp"
                android:paddingEnd="16dp"
                android:orientation="horizontal"
                app:layoutManager="androidx.recyclerview.widget.LinearLayoutManager"
                tools:listitem="@layout/item_recommended"
                tools:itemCount="3"/>

            <!-- 6. Restaurants Section (Layout will be created) -->
            <include layout="@layout/layout_section_header"
                android:layout_width="match_parent"
                android:layout_height="wrap_content"
                android:layout_marginTop="24dp"
                android:layout_marginStart="16dp"
                android:layout_marginEnd="16dp"
                app:layout_constraintTitleText="Restaurants" /> <!-- Pass title text -->
            <androidx.recyclerview.widget.RecyclerView
                android:id="@+id/recycler_restaurants"
                android:layout_width="match_parent"
                android:layout_height="wrap_content"
                android:layout_marginTop="8dp"
                android:clipToPadding="false"
                android:paddingStart="16dp"
                android:paddingEnd="16dp"
                android:orientation="horizontal"
                app:layoutManager="androidx.recyclerview.widget.LinearLayoutManager"
                tools:listitem="@layout/item_restaurant"
                tools:itemCount="2"/>


        </LinearLayout>
    </ScrollView>

    <!-- Bottom Navigation Bar -->
    <com.google.android.material.bottomnavigation.BottomNavigationView
        android:id="@+id/bottom_navigation"
        android:layout_width="0dp"
        android:layout_height="wrap_content"
        app:layout_constraintBottom_toBottomOf="parent"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintEnd_toEndOf="parent"
        android:background="?android:attr/windowBackground"
        app:menu="@menu/bottom_nav_menu" /> <!-- Create this menu file next -->


</androidx.constraintlayout.widget.ConstraintLayout>
```
*Note: `grey_light` and other colors/dimensions should be defined in `res/values/colors.xml` and `res/values/dimens.xml` for good practice.*

**Step 3: Create Layout Files for Each Section**

Now, create the individual layout files included in `activity_main.xml`.

**3.1. `layout_header.xml`**

Create `res/layout/layout_header.xml`.

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    android:padding="16dp">

    <LinearLayout
        android:id="@+id/header_text_container"
        android:layout_width="0dp"
        android:layout_height="wrap_content"
        android:orientation="vertical"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent"
        app:layout_constraintEnd_toStartOf="@+id/icon_cart">

        <TextView
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Hello, Delivery will take faster than usual"
            android:textColor="@android:color/darker_gray"
            android:textSize="14sp" />

        <TextView
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:text="Adibul Jabir"
            android:textColor="@android:color/black"
            android:textSize="18sp"
            android:textStyle="bold"
            android:layout_marginTop="4dp"/>

    </LinearLayout>

    <ImageView
        android:id="@+id/icon_cart"
        android:layout_width="32dp"
        android:layout_height="32dp"
        android:src="@drawable/ic_cart" <!-- Create an icon drawable -->
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintTop_toTopOf="parent"
        app:layout_constraintBottom_toBottomOf="parent"/>

</androidx.constraintlayout.widget.ConstraintLayout>
```
*Note: You'll need to add a cart icon drawable (e.g., `ic_cart.xml` or `ic_cart.png`) in your `res/drawable` folder.*

**3.2. `layout_banner.xml`**

Create `res/layout/layout_banner.xml`. We'll use a `CardView` for rounded corners and elevation. Inside, a `ConstraintLayout` to position elements.

```xml
<?xml version="1.0" encoding="utf-8"?>
<com.google.android.material.card.MaterialCardView
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="180dp"
    app:cardCornerRadius="16dp"
    app:cardElevation="4dp"
    app:cardBackgroundColor="@color/green_dark_gradient_start"> <!-- Define colors in colors.xml -->

    <androidx.constraintlayout.widget.ConstraintLayout
        android:layout_width="match_parent"
        android:layout_height="match_parent"
        android:background="@drawable/gradient_green"> <!-- Create a gradient drawable -->

        <ImageView
            android:id="@+id/banner_image"
            android:layout_width="120dp"
            android:layout_height="120dp"
            android:src="@drawable/img_salad" <!-- Add your salad image -->
            android:scaleType="centerCrop"
            app:layout_constraintStart_toStartOf="parent"
            app:layout_constraintTop_toTopOf="parent"
            app:layout_constraintBottom_toBottomOf="parent"
            android:layout_marginStart="16dp"/>

        <LinearLayout
            android:id="@+id/banner_text_container"
            android:layout_width="0dp"
            android:layout_height="wrap_content"
            android:orientation="vertical"
            android:layout_marginStart="16dp"
            app:layout_constraintStart_toEndOf="@+id/banner_image"
            app:layout_constraintTop_toTopOf="@+id/banner_image"
            app:layout_constraintEnd_toEndOf="parent"
            app:layout_constraintHorizontal_bias="0.0">

            <TextView
                android:layout_width="wrap_content"
                android:layout_height="wrap_content"
                android:text="Eid-ul-Adha Offer"
                android:textColor="@android:color/white"
                android:textSize="16sp" />

            <TextView
                android:layout_width="wrap_content"
                android:layout_height="wrap_content"
                android:text="25% OFF"
                android:textColor="@android:color/white"
                android:textSize="32sp"
                android:textStyle="bold"
                android:layout_marginTop="4dp"/>

            <TextView
                android:layout_width="wrap_content"
                android:layout_height="wrap_content"
                android:text="5-15 Jun"
                android:textColor="@android:color/white"
                android:textSize="14sp"
                android:layout_marginTop="4dp"/>

            <Button
                android:layout_width="wrap_content"
                android:layout_height="wrap_content"
                android:text="Get Now"
                android:layout_marginTop="16dp"
                android:paddingStart="24dp"
                android:paddingEnd="24dp"
                android:minHeight="0dp"
                android:paddingTop="8dp"
                android:paddingBottom="8dp"
                android:backgroundTint="@color/green_button" <!-- Define color -->
                style="@style/Widget.MaterialComponents.Button.Colored"
                app:cornerRadius="20dp"/> <!-- Make button rounded -->

        </LinearLayout>

        <!-- Add dots for indicator if needed, e.g., using LinearLayout with ImageViews -->
        <LinearLayout
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:orientation="horizontal"
            android:layout_marginBottom="8dp"
            app:layout_constraintBottom_toBottomOf="parent"
            app:layout_constraintStart_toStartOf="@+id/banner_image"
            app:layout_constraintEnd_toEndOf="@+id/banner_image">
            <!-- Add ImageViews for dots -->
             <ImageView android:layout_width="8dp" android:layout_height="8dp" android:src="@drawable/dot_selected" android:layout_marginEnd="4dp"/> <!-- Create dot drawables -->
             <ImageView android:layout_width="8dp" android:layout_height="8dp" android:src="@drawable/dot_unselected" android:layout_marginEnd="4dp"/>
             <ImageView android:layout_width="8dp" android:layout_height="8dp" android:src="@drawable/dot_unselected"/>
        </LinearLayout>

    </androidx.constraintlayout.widget.ConstraintLayout>
</com.google.android.material.card.MaterialCardView>
```
*Note: You'll need `img_salad.png` or similar, define `green_dark_gradient_start`, `green_button` colors, create `gradient_green.xml` drawable for the background gradient, and dot drawables in `res/drawable`.*

**3.3. `layout_search.xml`**

Create `res/layout/layout_search.xml`. Use a `CardView` for styling and `ConstraintLayout` or `LinearLayout` for internal arrangement.

```xml
<?xml version="1.0" encoding="utf-8"?>
<com.google.android.material.card.MaterialCardView
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    android:layout_width="match_parent"
    android:layout_height="wrap_content"
    app:cardCornerRadius="8dp"
    app:cardElevation="2dp"
    app:cardBackgroundColor="@android:color/white">

    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:orientation="horizontal"
        android:gravity="center_vertical"
        android:padding="12dp">

        <ImageView
            android:layout_width="24dp"
            android:layout_height="24dp"
            android:src="@drawable/ic_search" <!-- Create a search icon -->
            app:tint="@android:color/darker_gray"
            android:layout_marginEnd="8dp"/>

        <EditText
            android:layout_width="0dp"
            android:layout_weight="1"
            android:layout_height="wrap_content"
            android:hint="Feel the Taste of food..."
            android:textSize="16sp"
            android:textColorHint="@android:color/darker_gray"
            android:background="@android:color/transparent"
            android:singleLine="true"
            android:imeOptions="actionSearch"/>

        <ImageView
            android:layout_width="24dp"
            android:layout_height="24dp"
            android:src="@drawable/ic_filter" <!-- Create a filter icon -->
            app:tint="@android:color/darker_gray"
            android:layout_marginStart="8dp"/>

    </LinearLayout>
</com.google.android.material.card.MaterialCardView>
```
*Note: You'll need `ic_search` and `ic_filter` icons.*

**3.4. `layout_section_header.xml`**

Create `res/layout/layout_section_header.xml`. This layout can be reused for "Categories", "Recommended", and "Restaurants". We can make the title text a parameter using `tools:text` and update it in the include tag.

```xml
<?xml version="1.0" encoding="utf-8"?>
<androidx.constraintlayout.widget.ConstraintLayout
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="match_parent"
    android:layout_height="wrap_content">

    <TextView
        android:id="@+id/section_title"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:textSize="20sp"
        android:textStyle="bold"
        android:textColor="@android:color/black"
        app:layout_constraintStart_toStartOf="parent"
        app:layout_constraintTop_toTopOf="parent"
        app:layout_constraintBottom_toBottomOf="parent"
        tools:text="Section Title" /> <!-- Placeholder -->

    <TextView
        android:id="@+id/section_see_all"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:text="See All"
        android:textSize="14sp"
        android:textColor="@color/green_button" <!-- Use your primary/accent color -->
        app:layout_constraintEnd_toEndOf="parent"
        app:layout_constraintTop_toTopOf="parent"
        app:layout_constraintBottom_toBottomOf="parent"/>

</androidx.constraintlayout.widget.ConstraintLayout>
```
*Note: The `app:layout_constraintTitleText` in the include tag in `activity_main.xml` is a custom attribute not automatically handled. You would typically set this text in the Activity/Fragment code after inflating the layout, e.g., `binding.sectionHeaderCategories.findViewById(R.id.section_title).setText("Categories")` or create a custom compound view.* For simple cases, setting it in code is easiest.

**Step 4: Create Layout Files for RecyclerView Items**

Each type of item in the horizontal lists needs its own layout file.

**4.1. `item_category.xml`**

Create `res/layout/item_category.xml`.

```xml
<?xml version="1.0" encoding="utf-8"?>
<LinearLayout
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="wrap_content"
    android:layout_height="wrap_content"
    android:orientation="vertical"
    android:gravity="center_horizontal"
    android:layout_marginEnd="12dp"> <!-- Spacing between items -->

    <!-- Use ShapeableImageView for rounded images -->
    <com.google.android.material.imageview.ShapeableImageView
        android:id="@+id/category_image"
        android:layout_width="64dp"
        android:layout_height="64dp"
        android:scaleType="centerCrop"
        tools:src="@drawable/img_pizza" <!-- Placeholder image -->
        app:shapeAppearanceOverlay="@style/ShapeAppearance.Material3.Corner.Full" /> <!-- Make it circular -->

    <TextView
        android:id="@+id/category_name"
        android:layout_width="wrap_content"
        android:layout_height="wrap_content"
        android:layout_marginTop="4dp"
        tools:text="Pizza"
        android:textColor="@color/green_button" <!-- Match the text color in the image -->
        android:textSize="14sp"/>

</LinearLayout>
```
*Note: Need to add placeholder images like `img_pizza`, `img_burger`, etc. `ShapeAppearance.Material3.Corner.Full` is a style that makes the corners fully rounded, resulting in a circle if the width and height are equal.*

**4.2. `item_recommended.xml`**

Create `res/layout/item_recommended.xml`.

```xml
<?xml version="1.0" encoding="utf-8"?>
<com.google.android.material.card.MaterialCardView
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="160dp" <!-- Fixed width for items -->
    android:layout_height="wrap_content"
    android:layout_marginEnd="12dp"
    app:cardCornerRadius="8dp"
    app:cardElevation="2dp">

    <androidx.constraintlayout.widget.ConstraintLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:paddingBottom="8dp"> <!-- Padding at bottom inside card -->

        <ImageView
            android:id="@+id/recommended_image"
            android:layout_width="0dp"
            android:layout_height="100dp" <!-- Fixed height for image -->
            android:scaleType="centerCrop"
            app:layout_constraintTop_toTopOf="parent"
            app:layout_constraintStart_toStartOf="parent"
            app:layout_constraintEnd_toEndOf="parent"
            tools:src="@drawable/img_beef_steak" /> <!-- Placeholder -->

        <TextView
            android:id="@+id/recommended_name"
            android:layout_width="0dp"
            android:layout_height="wrap_content"
            android:layout_marginTop="8dp"
            android:layout_marginStart="8dp"
            android:layout_marginEnd="8dp"
            android:textColor="@android:color/black"
            android:textSize="14sp"
            android:textStyle="bold"
            app:layout_constraintTop_toBottomOf="@+id/recommended_image"
            app:layout_constraintStart_toStartOf="parent"
            app:layout_constraintEnd_toStartOf="@+id/button_add"
            tools:text="Beef Steak" />

        <TextView
            android:id="@+id/recommended_price"
            android:layout_width="wrap_content"
            android:layout_height="wrap_content"
            android:layout_marginTop="4dp"
            android:layout_marginStart="8dp"
            android:textColor="@android:color/darker_gray"
            android:textSize="12sp"
            app:layout_constraintTop_toBottomOf="@+id/recommended_name"
            app:layout_constraintStart_toStartOf="parent"
            tools:text="$ 9.99" />

        <com.google.android.material.button.MaterialButton
            android:id="@+id/button_add"
            android:layout_width="40dp"
            android:layout_height="40dp"
            android:layout_marginEnd="8dp"
            android:insetLeft="0dp"
            android:insetTop="0dp"
            android:insetRight="0dp"
            android:insetBottom="0dp"
            app:cornerRadius="20dp" <!-- Make it circular -->
            app:icon="@drawable/ic_add" <!-- Create an add icon -->
            app:iconGravity="textStart"
            app:iconPadding="0dp"
            app:iconSize="24dp"
            app:tint="@android:color/white"
            android:backgroundTint="@color/green_button" <!-- Use your green color -->
            app:layout_constraintBottom_toBottomOf="parent"
            app:layout_constraintEnd_toEndOf="parent"
            app:layout_constraintTop_toTopOf="@+id/recommended_name" />

    </androidx.constraintlayout.widget.ConstraintLayout>
</com.google.android.material.card.MaterialCardView>
```
*Note: Need placeholder images and an `ic_add` icon.*

**4.3. `item_restaurant.xml`**

Create `res/layout/item_restaurant.xml`. The image in the example is quite large; a typical restaurant list item might show a smaller image, name, rating, etc. Let's create a card that focuses on the image as seen, perhaps implying more details would be shown on click.

```xml
<?xml version="1.0" encoding="utf-8"?>
<com.google.android.material.card.MaterialCardView
    xmlns:android="http://schemas.android.com/apk/res/android"
    xmlns:app="http://schemas.android.com/apk/res-auto"
    xmlns:tools="http://schemas.android.com/tools"
    android:layout_width="300dp" <!-- Adjust width as needed -->
    android:layout_height="180dp" <!-- Adjust height as needed -->
    android:layout_marginEnd="12dp"
    app:cardCornerRadius="8dp"
    app:cardElevation="2dp">

    <!-- This layout shows a large image, similar to the example collage.
         For a real app, you might overlay text (restaurant name, rating) -->
    <ImageView
        android:id="@+id/restaurant_image"
        android:layout_width="match_parent"
        android:layout_height="match_parent"
        android:scaleType="centerCrop"
        tools:src="@drawable/img_restaurants_collage" /> <!-- Placeholder image -->

    <!-- Optional: Overlay content -->
    <!--
    <TextView
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:text="Restaurant Name"
        android:textColor="@android:color/white"
        android:textSize="18sp"
        android:textStyle="bold"
        android:layout_gravity="bottom"
        android:padding="12dp"
        android:background="#80000000"/> // Semi-transparent black background
    -->

</com.google.android.material.card.MaterialCardView>
```
*Note: Need placeholder images like `img_restaurants_collage`.*

**Step 5: Create Bottom Navigation Menu**

1.  Right-click on the `res` directory -> `New` -> `Android Resource File`.
2.  Set `File name` to `bottom_nav_menu`.
3.  Set `Resource type` to `Menu`.
4.  Click `OK`.
5.  Add menu items corresponding to the icons in the bottom bar:

```xml
<?xml version="1.0" encoding="utf-8"?>
<menu xmlns:android="http://schemas.android.com/apk/res/android">

    <item
        android:id="@+id/nav_home"
        android:icon="@drawable/ic_home_filled" <!-- Create selected icon -->
        android:title="Home" />

    <item
        android:id="@+id/nav_cart"
        android:icon="@drawable/ic_basket" <!-- Create icon -->
        android:title="Cart" />

    <item
        android:id="@+id/nav_fork_knife"
        android:icon="@drawable/ic_fork_knife" <!-- Create icon -->
        android:title="Food" />

    <item
        android:id="@+id/nav_profile"
        android:icon="@drawable/ic_person" <!-- Create icon -->
        android:title="Profile" />

    <item
        android:id="@+id/nav_menu"
        android:icon="@drawable/ic_menu" <!-- Create icon -->
        android:title="More" />

</menu>
```
*Note: You'll need drawable icons for each menu item.* The selected 'Home' item has a different background shape in the original image; this requires custom styling or potentially using a separate View for the selected item within the BottomNavigationView structure, which is more advanced customization. For a standard `BottomNavigationView`, the selection is indicated by icon tint and text color.

**Step 6: Style Resources (`colors.xml`, `dimens.xml`, `drawables`)**

1.  Create/Open `res/values/colors.xml` and define your colors:

    ```xml
    <?xml version="1.0" encoding="utf-8"?>
    <resources>
        <color name="grey_light">#F5F5F5</color> <!-- Or match the exact background color -->
        <color name="green_dark_gradient_start">#1A5D1A</color> <!-- Approx darker green -->
        <color name="green_button">#4CAF50</color> <!-- Approx green button color -->
        <!-- Add other colors used -->
    </resources>
    ```
2.  Create/Open `res/values/dimens.xml` for dimensions like padding, margins, text sizes if you prefer.
3.  Add your drawable icons (`ic_cart.xml`, `ic_search.xml`, `ic_filter.xml`, `ic_add.xml`, etc.) and placeholder images (`img_salad.png`, `img_pizza.png`, etc.) to `res/drawable`.
4.  Create the gradient drawable `res/drawable/gradient_green.xml`:

    ```xml
    <?xml version="1.0" encoding="utf-8"?>
    <shape xmlns:android="http://schemas.android.com/apk/res/android">
        <gradient
            android:angle="0"
            android:startColor="@color/green_dark_gradient_start"
            android:endColor="#4CAF50" /> <!-- Add your end color -->
        <corners android:radius="16dp"/> <!-- Match CardView corner radius -->
    </shape>
    ```

**Step 7: Link Layouts and Data (Basic - Requires Kotlin/Java)**

The XML defines the structure, but `RecyclerView`s need adapters and data. While a full implementation is beyond just UI layout, here's what you'd do in your Activity/Fragment:

1.  Get references to your `RecyclerView`s:
    ```kotlin
    val recyclerCategories = findViewById<RecyclerView>(R.id.recycler_categories)
    val recyclerRecommended = findViewById<RecyclerView>(R.id.recycler_recommended)
    val recyclerRestaurants = findViewById<RecyclerView>(R.id.recycler_restaurants)
    ```
2.  Create data classes for Category, RecommendedItem, Restaurant.
3.  Create `RecyclerView.Adapter` subclasses for each list (`CategoryAdapter`, `RecommendedAdapter`, `RestaurantAdapter`). These adapters will:
    *   Inflate the corresponding item layout (`item_category.xml`, etc.) in `onCreateViewHolder`.
    *   Bind the data to the views in the item layout in `onBindViewHolder`.
    *   Handle the list of data items.
4.  Create some dummy data lists in your Activity/Fragment.
5.  Set up the `RecyclerView`s:
    ```kotlin
    // Example for Categories
    val categories = listOf(
        Category(R.drawable.img_pizza, "Pizza"),
        Category(R.drawable.img_burger, "Burger"),
        // ... add more categories
    )
    val categoryAdapter = CategoryAdapter(categories) // Your custom adapter
    recyclerCategories.layoutManager = LinearLayoutManager(this, LinearLayoutManager.HORIZONTAL, false)
    recyclerCategories.adapter = categoryAdapter

    // Repeat for Recommended and Restaurants
    // You might need to set `layoutManager` in code if not set via XML `app:layoutManager`
    ```
*Note: Implementing the Adapters is a significant part of the development process, but this guide focuses on the visual layout structure.*

**Step 8: Refinement**

*   Adjust padding, margins, sizes (`dp` and `sp`) to match the screenshot closely.
*   Fine-tune colors and fonts.
*   Ensure all required drawables are added.
*   Test on different screen sizes and densities.

This detailed breakdown covers the creation of the XML layout files and structure necessary to achieve the visual appearance of the provided UI. Remember that a complete functional app requires implementing the data handling, logic, and user interactions in your Kotlin/Java code.