
# Registratoin System in C

Artist and song registration system with login.

## 🎯 Objective
Apply knowledge of algorithms and programming logic to make a registration system, in which:
- must have two structures that talk to each other;
- the data in the structures should be dynamically allocated and reallocated every 5 in 5 when necessary;
- must save the data created in a binary file and reload it on reboot;
- must have a security system using Caesar's cipher.
## 📝 Description
Besides having a login system it has six main operations:
- *Register*
- *Edit*
- *List*
- *Delete*
- *Search*
- *Export*<br><br>The *edit*, *delet* and *search* operations can be performed on both artists and songs. They can be accessed by two different fields (e.g., edit an artist by his own ID or by a song ID).
## 🔧 Usage
This project uses *Makefile*  to compile and run.
It has three basics operations:
- **make**: compiles the project;
- **make run**: executes the project;
- **make clean**: remove unnecessary files from the project;
