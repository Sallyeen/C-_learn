PROJECT(HELLO)
ADD_SUBDIRECTORY(src bin)
INSTALL(FILES COPYRIGHT README.md DESTINATION /home/gw00243982/Desktop/GJ/C++_learn/code/test)
INSTALL(PROGRAMS runhello.sh DESTINATION /home/gw00243982/Desktop/GJ/C++_learn/code/test)
INSTALL(DIRECTORY doc/ DESTINATION /home/gw00243982/Desktop/GJ/C++_learn/code/test)

