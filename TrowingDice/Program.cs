using System;
using System.IO;
using TrowingDice;

/**	
 *  This is remade version of my first ever programing assignment.
**/
namespace ThrowingDice
{
	internal class TrowingDice
	{
		static void Main(string[] args)
		{
			Dice dice = new Dice();

			for (int i = 0; i < 20; i++)
			{
				Console.WriteLine(dice.ThrowDice());

			}

			Console.WriteLine("Hello, World!");
		}
	}
}


