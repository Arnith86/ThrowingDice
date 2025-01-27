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

		Player player;

		Dice[] playerDice;
		Dice[] npcDice;

		bool playAnotherGame;


		// This method will handel all game logic 
		public Gamelogic() 
		{

			// Regex pattern, only positive integers
			string integerPattern = @"^\d+$";


			player = new Player();

			playerDice = new Dice[2];
			playerDice[0] = new Dice();
			playerDice[1] = new Dice();

			npcDice = new Dice[2];
			npcDice[0] = new Dice();
			npcDice[1] = new Dice();		
			
			playAnotherGame = true;


			while (playAnotherGame) 
			{
				if (player.getDeposit() == 0) 
				{
					Console.WriteLine("How much money do you want do deposit? \n " +
										"5000kr is the upper limit! "); 
					
					string inputedDeposit = Console.ReadLine();
					
					if (!(Regex.IsMatch(inputedDeposit, integerPattern)))
					{
						Console.WriteLine("Only integer values between 100 and 5000 are permited!");
					}

					int tempDepositValue = int.Parse(inputedDeposit);
					
					if (tempDepositValue < 100 || tempDepositValue > 5000)
					{
						Console.WriteLine("Only integer values between 100 and 5000 are permited!");
					}
					
				}
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
