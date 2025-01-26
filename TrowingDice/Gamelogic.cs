using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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
			player = new Player();
			playerDice = new Dice[2];
			npcDice = new Dice[2];

			playAnotherGame = false;



			while (playAnotherGame) 
			{
				
			}
			
			// when this part is reached END game (exit program).

		}


		// Will handles a single round of dice throws 
		private bool GameRound(Dice[] playerDice, Dice[] npcDice)
		{

			ThrowDiceSet(playerDice);
			ThrowDiceSet(npcDice);

			// test the trow results 
			foreach (Dice dice in playerDice) { Console.WriteLine(dice.DiceValue); }
			foreach (Dice dice in npcDice) { Console.WriteLine(dice.DiceValue); }

			return true; // depends on who wins 
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
