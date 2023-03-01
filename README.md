																													Grocery Market Application
																																
This is a terminal-based application written in C++ that simulates a grocery market. The application provides a basic interface for users to perform various tasks such as adding items to their cart, checking out, and paying using various methods. The application also includes a basic login system that allows users to create an account and log in to access the application's features.

																													Usage
																																					
When the application starts, the user is prompted to either create an account or log in. The login system supports three types of users: admin, manager, and regular user. Each user has a unique login screen, and the application uses polymorphism to implement different payment methods based on the user's login type.

Once the user logs in, they can perform various tasks such as adding items to their cart, checking out, and paying using a dummy payment system that simulates payments using credit cards or Easypaisa.

																																		Special Features
																																		
Polymorphism has been used to implement different payment methods based on the user's login type.
Inheritance has been used to implement a basic login system with different login screens for each user type.
Terminal colours have been used using ANSI that change accordingly for each user.

																																			Limitations
																																			
Data handling is only done through basic arrays and is local.
The application does not have the capability to generate receipts.
The payment system is only a dummy implementation and cannot be used for actual payments.
The application does not have a graphical user interface and is based solely on a terminal interface.
The application does not have the capability to handle large amounts of data efficiently.
The login system only supports a basic username and password system and does not have additional security features such as two-factor authentication or password hashing.
The application does not have a database, and all data is stored locally.
The user has to delete .BIN files on each run for a fresh application start.

																																			What I Learned
																																			
Basic concepts of OOP
Binary file handling
First steps into databases using hierarchical systems
License
This application is licensed under the MIT License.

																																		Acknowledgments
This application was created as a university student's first OOP project.

Please let me know if you need any further modifications or if you have any questions.
