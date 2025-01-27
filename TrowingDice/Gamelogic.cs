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

		Player player;

		Dice[] playerDice;
		Dice[] npcDice;

		bool playAnotherGame;


		// This method will handel all game logic 
		public Gamelogic() 
		{
			ConsoleMessages consoleMessages = ConsoleMessages.Instance;
			
			// Regex pattern, only positive integers
			string integerPattern = @"^\d+$";


			player = new Player();

			// Player and Npc dice hands
			playerDice = new Dice[2];
			playerDice[0] = new Dice();
			playerDice[1] = new Dice();
			npcDice = new Dice[2];
			npcDice[0] = new Dice();
			npcDice[1] = new Dice();		
			
			playAnotherGame = true;

			consoleMessages.DisplayMessage(_WELCOME);

			while (playAnotherGame) 
			{
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

				GameRound(playerDice, npcDice);
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
