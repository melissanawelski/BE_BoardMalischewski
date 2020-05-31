# BE_BoardMelissaXiaotong-final
BE_BoardMelissaXiaotong-final is a C++ library simulation for domotic applications, providing control of temperature and luminosity. 

To start the program, first compile with ./compile_linux.sh if you are on linux or with ./compile_mac.sh if you are on a MAC.
Then, you can execute it with ./arduino.

Several tests are possible :


---First test : test of presence
In mydevices.cpp nb_humain= 0 and see that no parameter is changing.
Then put nb_humain =1 or more, compile, execute to see that the system checks the hour.


---Second test : test of the hour
The program is make to use the hour of your machine, so you can test the "day part".
If you want to test the "night part", change the day range, line 299 in mydevices.cpp.
Then, compile, execute and the program will adapt the temperature and the luminosity.

---Third test : button test
Add a file on.txt in src. It means that the user pushes a button in day time to say that he doesn't want the curtain to open.Compile, execute and you will see that the light is turned on by the program.

Enjoy the simulation!!




