using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TrowingDice
{
	/** 
	 * Player class: keeps track of current balance and bet.
	 **/
	class Player
	{
		private int deposit;
		private int bet; 

		public Player()
		{
			deposit = 0;
			bet = 0;
		}

		public void setBet(int bet)
		{
			this.bet = bet;
		}

		public int getBet() 
		{
			return this.bet;
		}

		public void setDeposit(int deposit) 
		{
			this.deposit = deposit;
		}

		public int getDeposit() 
		{
			return this.deposit;
		}
	}
}
