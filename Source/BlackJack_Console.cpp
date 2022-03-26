#include "Deck.h"
#include"Player.h"

void WelcomePlayer(Player& player)
{
    std::cout << "Welcome, " << player.GetName() << ".\n";
    std::cout << "You have " << player.GetBalance() << " chips in your account.\n";
}

enum class Result
{
    win,
    loose,
    tie
};

void DealCardTo(Dealer& dealer, Card& card, Deck& deck)
{
    card = deck.DealCard();
    std::cout << "Card to "<< dealer.GetName() << " : " << card << '\n';
    dealer.AddScore(card.GetValue());
    std::cout << dealer.GetName() <<"'s score is : " << dealer.GetScore() << '\n';
}

int PlayerTurn(Player& player, Card& card, Deck& deck)
{
    while (true)
    {
        if (player.HasBlackJack())
        {
            std::cout << "You have a BlackJack.\n";
            return 1;
        }
        else if (player.IsBust())
        {
            std::cout << "You are Busted.\n";
            return 0;
        }
        std::cout << "(H)it or (S)tand : ";
        char option{};
        std::cin >> option;
        if (option == 'h' or option == 'H')
        {
            DealCardTo(player, card, deck);
        }
        else { return 2; }
    }
}

int DealerTurn(Dealer& dealer, Card& card, Deck& deck)
{   
    std::cout << "Face down card of dealer is : " <<'\n';
    
    while (dealer.GetScore() <= GameStats::minScore)
    {
        DealCardTo(dealer, card, deck);
        if (dealer.HasBlackJack())
        {
            std::cout << "Dealer has a BlackJack.\n";
            return 0;

        }
        else if (dealer.IsBust())
        {
            std::cout << "Dealer Busted.\n";
            return 1;
        }
    }
    return 2;
   
}

void ChangeBalance(bool hasPlayerWon, Player& player)
{
    if (hasPlayerWon)
    {
        std::cout << player.GetBetAmount() << " credited to your account.\n";
        player.AddBetToBalance();
        std::cout << "Your current balance is : " << player.GetBalance() << '\n';
    }
    else
    {
        std::cout << player.GetBetAmount() << " dedited from your account.\n";
        player.SubtractBetFromBalance();
        std::cout << "Your current balance is : " << player.GetBalance() << '\n';
    }
}

Result CheckWinner(Player& player, Dealer& dealer)
{
    if (dealer.GetScore() < player.GetScore())
    {
        std::cout << "You Win !!! \n";
        ChangeBalance(true, player);
        return Result::win;
    }
    else if (dealer.GetScore() > player.GetScore())
    {
        std::cout << "You Lost !!! \n";
        ChangeBalance(false, player);
        return Result::loose;
    }
    else
    {
        std::cout << "It's a tie. \n";
        return Result::tie;
    }
}


Result PlayBlackJack(Player& player, Deck& deck)
{
    Dealer dealer{};
  
    std::cout << "First card to dealer face down.\n";

    Card card{};

    DealCardTo(dealer, card, deck);
    DealCardTo(player, card, deck);
    DealCardTo(player, card, deck);


    int playerMove{ PlayerTurn(player, card, deck) };
    if (!playerMove)
    {
        ChangeBalance(false, player);
        return Result::loose;
    }
    else if (playerMove == 1)
    {
        ChangeBalance(true, player);
        return Result::win;
    }
    int dealerMove{ DealerTurn(dealer, card, deck) };
    if (!dealerMove)
    {
        ChangeBalance(false, player);
        return Result::loose;
    }
    else if (dealerMove == 1)
    {
        ChangeBalance(true, player);
        return Result::win;
    }

    return CheckWinner(player, dealer);
}

void SetBet(int& bet, Player& player)
{
    bool isBetSet{ false };
    while (!isBetSet)
    {
        std::cout << "Place your bet : ";
        std::cin >> bet;
        if (bet <= player.GetBalance())
        {
            player.SetBetAmount(bet);
            isBetSet = true;
        }
        else
        {
            std::cout << "You have only" << player.GetBalance() << " chips in your account.\n";
            std::cout << "Can Not Set Bet for " << bet << " chips.\n";
        }
    }
}

bool ReplayGame(Player& player, int& bet)
{
    std::cout << "--------------------------\n";
    std::cout << "Do you want to try again?\n";
    std::cout << "To Try Again Press 'Y'.\n";
    std::cout << "To Quit Press Any other key.";
    char input{};
    std::cin >> input;
    if (input == 'y' || input == 'Y')
    {
        player.Reset();
        SetBet(bet, player);
        return true;
    }

    return false;
}

int main()
{
    Player player{ "ABCD" };
    Deck deck{};
    deck.Shuffle();

    WelcomePlayer(player);
    int bet{};
    SetBet(bet, player);

    bool keepPlaying{true};
    while (keepPlaying)
    {
        Result r = PlayBlackJack(player, deck);
        if (player.GetBalance() == 0)
        {
            std::cout << "You have 0 chips in your account.\nGame Over\n";
            keepPlaying = false;
            
        }
        else
        {
            keepPlaying = ReplayGame(player, bet);
        }
    }
    return 0;
}






