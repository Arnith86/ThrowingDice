using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrowingDice
{

	/**
	 * The class represents a six sided die, and the rolling of said die. 
	 **/

	class Dice
	{
		public int DiceValue { get; set; }

		public Dice() 
		{
			DiceValue = 1; 
		}

		public int ThrowDice()
		{
			Random randomSeed = new Random();
			
			return DiceValue = randomSeed.Next(1, 7);
		}
	}
}
