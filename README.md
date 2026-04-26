This is a number guessing game were you can switch between difficulties, clean game menu and multiplayer

To compile use these commands, g++ main.cpp Game.cpp Player.cpp FileManager.cpp ScoreManager.cpp NetworkManager.cpp -o game -lws2_32 | g++ server.cpp -o server 
-lws2_32 | g++ client.cpp -o client -lws2_32. To run use these, ./server | ./client | ./game


When you use "./server" you create the server. When you use "./client" you create a player that only exist in that server. Or you can take a player from another server to put their player in your sever. When you use "./game" you start the game, but you have to create a player if you already have one.