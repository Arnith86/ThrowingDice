﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrowingDice
{
	/** 
	 * This class contains all the console messages used in the program 
	 **/
	public class ConsoleMessages
	{
		private static ConsoleMessages instance;
		Dictionary<string, string> messages;

		private ConsoleMessages() 
		{
			messages = new Dictionary<string, string>
			{
				{ "Welcome ", "The game involves the user and the computer rolling two dice at a time for three rounds. " +
								"The player who rolls the highest individual die in a round wins that round. " +
								"The best out of three rounds determines the winner." },
				{ "Start_Deposit", "How much money do you want do deposit? \n 5000kr is the upper limit!" },
				{ "Deposit_Error", "Only integer values between 100 and 5000 are permited!" },
				{ "Start_Bet", "What will you bet? \n 1: 100kr \n 2: 200kr \n 3: 500kr" },
				{ "Bet_Error", "Provide an integer between 1 and 3!" }
			};
		}

		// Retrives the desired message, if it exists.
		public string GetMessage(string key)
		{
			if (messages.TryGetValue(key, out string message))
			{
				return message;
			}

			return $"Message for key '{key}' not found.";
		}

		public void DisplayMessage(string key)
		{
			Console.WriteLine(GetMessage(key));
		}
	}
}
