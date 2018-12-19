# README
~Written and made by Raj-Preet Chaudhry, Uthra Umashanker, and Sophia Fondell~

## SERVER
webserv.c serves as our basic server, and is set up through the socket interface. Any web browser can be used as the client. Use ***BUILD COMMANDS HERE*** to make the server, and do ./buzzwire.

## HARDWARE
This is a combination of the well known Buzz Wire game and a basic C webserver. The Buzz Wire game takes the time needed to run the loop through the course, and stops the timer after pressing the button (manually pressed after the player finishes the course). If the loop touches the course, a loud buzz plays, and an extra amount of time is added to the total time as a penalty. The time is then sent to the web server written in a text file, serving as a type of "high score" table. While playing the game, a melody plays, indicating that the machine is on.

## FOR ME
char file[1024] = "FINDFDHERE";
