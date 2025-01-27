using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Text.RegularExpressions;

namespace TrowingDice
{
	class Gamelogic
	{
		string _WELCOME = "Welcome";
		string _START_DEPOSIT = "Start_Deposit";
		string _DEPOSIT_ERROR = "Deposit_Error";
		string _CURRENT_BALANCE = "Current_Balance";
		string _START_BET = "Start_Bet";
		string _BET_ERROR_INT = "Bet_Error_Int";
		string _BET_BALANCE_ERROR_ = "Bet_Balance_Error";

		Player player;

		Dice[] playerDice;
		Dice[] npcDice;

		bool playAnotherGame;
		bool betRegistered; 


		// This method will handel all game logic 
		public Gamelogic() 
		{
			ConsoleMessages consoleMessages = ConsoleMessages.Instance;
			
			// Regex pattern, only positive integers
			string integerPattern = @"^\d+$";
			string oneTwoThreePattern = @"^[1-3]+$";

			Dictionary<int, int> betValues = new Dictionary<int, int>
			{
				{1, 100},
				{2, 300},
				{3, 500}
			};

			// Index 1: player, Index 2: Npc
			int[] roundWinCount = new int[] { 0, 0 };

			player = new Player();

			// Player and Npc dice hands
			playerDice = new Dice[2];
			playerDice[0] = new Dice();
			playerDice[1] = new Dice();
			npcDice = new Dice[2];
			npcDice[0] = new Dice();
			npcDice[1] = new Dice();		
			
			playAnotherGame = true;
			betRegistered = false; 

			// Displays welcome message 
			consoleMessages.DisplayMessage(_WELCOME);

			while (playAnotherGame) 
			{
				// Asks how much player wants to place in account
				if (player.GetDeposit() == 0) consoleMessages.DisplayMessage(_START_DEPOSIT);

				// Regesters player deposit sum
				while (player.GetDeposit() == 0) 
				{
					string inputedDeposit = Console.ReadLine();

					// Only Integer values between 100 and 5000 is allowed
					if (!Regex.IsMatch(inputedDeposit, integerPattern) ||
						!int.TryParse(inputedDeposit, out int tempDepositValue) ||
						tempDepositValue < 100 || tempDepositValue > 5000)
					{
						consoleMessages.DisplayMessage(_DEPOSIT_ERROR);
					}
					else
					{
						player.SetDeposit(tempDepositValue);
					}
				}

				// Displays current balance to player
				consoleMessages.DisplayMessage(_CURRENT_BALANCE, player.GetDeposit());

				// Register player bet
				consoleMessages.DisplayMessage(_START_BET);

				while (!betRegistered)
				{
					// Get player bet
					string inputBet = Console.ReadLine();

					// Bet error handeling
					// Integer outside of range
					if (!Regex.IsMatch(inputBet, oneTwoThreePattern))
					{
						consoleMessages.DisplayMessage(_BET_ERROR_INT);
						continue;
					}

					int tempBetValue = betValues[int.Parse(inputBet)];
					
					// Bet exceeds current founds 
					if (tempBetValue > player.GetDeposit())
					{
						consoleMessages.DisplayMessage(_BET_BALANCE_ERROR_);
						continue;
					}

					player.SetBet(tempBetValue);
					player.SetDeposit(player.GetDeposit() - tempBetValue);

					betRegistered = true;
				}

				// Will conduct new rounds untill either Player or Npc has two wins
				do
				{
					// Registers winner of round 
					if (GameRound(playerDice, npcDice)) roundWinCount[0]++;
					else roundWinCount[1]++;

				} while (!(roundWinCount[0] == 2) && !(roundWinCount[1] == 2));

				
			}
			
			// when this part is reached END game (exit program).

		}


		// Will handles a single round of dice throws 
		private bool GameRound(Dice[] playerDice, Dice[] npcDice)
		{
			int playerHighest = 0;
			int npcHighest = 0; 

			while (playerHighest == npcHighest) 
			{
				ThrowDiceSet(playerDice);
				ThrowDiceSet(npcDice);

				playerHighest = maxDice(playerDice);
				npcHighest = maxDice(npcDice);

				// Player won
				if (playerHighest > npcHighest) { Console.WriteLine("Player won!"); return true; }
				// Npc won
				else if (playerHighest < npcHighest) { Console.WriteLine("Npc won!"); return false; }
				// It was a draw, another throw will be conducted.
				else { Console.WriteLine("It was a draw, throw again!"); }
			}

			return true; // depends on who wins 
		}

		// Returns highest die value of throw
		private int maxDice(Dice[] dices)
		{
			return int.Max(dices[0].DiceValue, dices[1].DiceValue);	
		}

		private Dice[] ThrowDiceSet(Dice[] dices)
		{
			foreach (Dice dice in dices)
			{
				dice.ThrowDice();
			}

			return dices;
		}
	}
}
