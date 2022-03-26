@ echo off

echo D:

D:

IF %ERRORLEVEL% NEQ 0 goto:break_process
echo cd D:/CPP_Projects/Console Projects/Blackjack_Console
cd D:/CPP_Projects/Console Projects/Blackjack_Console
IF %ERRORLEVEL% NEQ 0 goto:break_process
echo g++ -c Source/Deck.cpp -o Object/Deck.o -I Header
g++ -c Source/Deck.cpp -o Object/Deck.o -I Header
IF %ERRORLEVEL% NEQ 0 goto:break_process
echo g++ -c Source/Card.cpp -o Object/Card.o -I Header
g++ -c Source/Card.cpp -o Object/Card.o -I Header
IF %ERRORLEVEL% NEQ 0 goto:break_process
echo g++ Object/BlackJack_Console.o Object/Card.o Object/Dealer.o Object/Deck.o Object/Player.o -o Output/Blackjack_Console.exe
g++ Object/BlackJack_Console.o Object/Card.o Object/Dealer.o Object/Deck.o Object/Player.o -o Output/Blackjack_Console.exe
IF %ERRORLEVEL% NEQ 0 goto:break_process
echo "Output/Blackjack_Console.exe"
"Output/Blackjack_Console.exe"
IF %ERRORLEVEL% NEQ 0 goto:break_process
:break_process
pause
