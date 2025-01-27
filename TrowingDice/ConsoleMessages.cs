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
				{ "Welcome", "The game involves the player and the computer rolling two dice at a time for three rounds. \n" +
								"The player who rolls the highest individual die in a round wins that round. \n" +
								"The best out of three rounds determines the winner.\n" },
				{ "Start_Deposit", "How much money do you want do deposit? \nRegister a value between 100 - 5000kr.\n" },
				{ "Deposit_Error", "Only integer values between 100 and 5000 are permited! \nTry again!\n" },
				{ "Current_Balance", "kr in account! \n" },
				{ "Start_Bet", "How much will you bet? \n 1: 100kr \n 2: 300kr \n 3: 500kr" },
				{ "Bet_Error_Int", "Provide an integer between 1 and 3!" },
				{ "Bet_Balance_Error", "Bet exceeds your current funds. Please try again" }
			};
		}

		public static ConsoleMessages Instance 
		{ 
			get 
			{
				if (instance == null)
				{
					instance = new ConsoleMessages();
				}
				return instance; 
			} 
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

		public void DisplayMessage(string key, int value = -1)
		{
			if (value == -1)
			{
				Console.WriteLine(GetMessage(key));
			}
			else
			{
				Console.WriteLine(value + GetMessage(key));
			}
		}
	}
}
