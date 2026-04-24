This is a number guessing game were you can switch between difficulties, clean game menu and multiplayer

To compile use these commands, g++ main.cpp Game.cpp Player.cpp FileManager.cpp ScoreManager.cpp NetworkManager.cpp -o game -lws2_32 | g++ server.cpp -o server 
-lws2_32 | g++ client.cpp -o client -lws2_32. To run use these, ./server | ./client | ./game
