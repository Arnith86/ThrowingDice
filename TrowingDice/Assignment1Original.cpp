#include <iostream>
#include <limits>
#include <ctime>

using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;

int main()
{
	/* winnings:	players winnings */
	/* wallet:		money in player account */
	/* deposit:		placeholder for money transfer to the wallet */
	
	/* a random number generator using time */ 

	srand(time(0));

	int winnings, wallet;

	char yes_no, replay;

	replay = 'j';
	winnings = 0;
	wallet = 0;

	cout << "			-------------------------" << endl;
	cout << "			|       V\x84lkommen!       |" << endl;
	cout << "			-------------------------" << endl << endl << endl;
	cout << "---------------" << endl;
	cout << "- Spelregler: -" << endl;
	cout << "---------------------------------------------------------------------------------------" << endl;
	cout << "- Spelaren och Datorn kastar tv\x86 t\x84rningar var. " << "F\x94rst till tv\x86 vunna kast vinner spelet!" << endl
		 << "- Om t\x84rningarna med h\x94st v\x84rde \x84r lika, r\x86knas den totala v\x84rdet p\x86 kastet." << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;

	cout << "- Du kan satsa 100, 200 eller 300kr per omg\x86ng!" << endl << endl << endl;

	cout <<	"				****************" << endl;
	cout <<	"				* Lycka till!! *" << endl;
	cout <<	"				****************" << endl << endl;

	/*start of the loop*/
		while (replay == 'j')
		{

			//* checks your $ if empty asks if you want to fill upp *//
			if (winnings < 100 && wallet < 100)  
			{

				cout << "Du har inte tillr\x84kligt med pengar f\x94r att kunna forts\x84tta spelet.\n"
					<< "Vill du s\x84tta in pengar p\x86 ditt spel konto?" << endl;

			
					//*makes sure user only answer j or n, otherwise it loops*//  
					do {
						cout << "--------------------------------" << endl;
						cout << "Svara med (j) Ja eller (n) Nej: ";
							cin >> yes_no;
							cout << endl; 

					} while (yes_no != 'j' && yes_no != 'n');

						
				
				if (yes_no == 'n') 
				{

					//*asking if player wants to end game*//
					cout << "-------------------------------------------------------------------------------------------" << endl;
					cout << "Du angav att du inte vill s\x84tta in pengar, " << "betyder det att du vill avsluta spelet?";
					
					do {

						cout << endl << "Svara med Ja (j) eller Nej (n): ";
							cin >> yes_no;
							cout << endl;

					} while (yes_no != 'j' && yes_no != 'n');
					
						
					
					if (yes_no == 'j') //*ends game*// 
					{
						cout << "---------------------------------------" << endl; 
						cout << "Vad tr\x86kigt.." << endl << endl;

						cout << "*******************" << endl;
						cout << "* V\x84lkommen \x86ter! *" << endl;
						cout << "*******************" << endl;

						return 0;
					}

				}
				
				//*the process of adding founds*//

				int deposit; 
				cout << "------------------------------------------------------------" << endl;
				cout << "Du kan g\x94ra en ins\x84ttning p\x86 mellan 100 och 5000kr." 
					 << endl << "Hur mycket vill du s\x84tta in?: ";
				
					
					do {
					
							cin >> deposit; 
							cout << "--------------------" << endl;
					
						//* used in case of character input in deposit*//
						cin.clear();
						cin.ignore(numeric_limits <streamsize>::max(), '\n');
						
							if ((!(deposit >= 100 && deposit <= 5000)))
							{
								cout << "F\x94rs\x94k igen.." << endl;

							}
					}while (!(deposit >= 100 && deposit <= 5000));
				

				wallet = wallet + deposit;

				
			}

			int userWonRound , compWonRound  , bet = 0;
			userWonRound = 0;
			compWonRound = 0;

			char wall_win;
				
				cout << "Dina innestaende pengar:" << endl 
					 <<  "-----------------------" << endl
					 << "Spelkonto: " << wallet << endl
					 << "Vinstsaldo: " << winnings << endl << endl;
				cout << "---------------------------------------------------------------------------" << endl; 
				cout << "Vill du anv\x84nda pengar fr\x86n Spelsaldo (s) eller Vinstsaldo (v)?: " << endl; 
				cout << "Vinstpengar kan \x84ndast anv\x84ndas om du lyckats samla ihop minst 100kr" << endl;
				cout << "--------------------------------------------------------------------------" << endl;

						do {
							cout << "Svara med ett 's' eller 'v': " ;
								cin >> wall_win;
							cout << endl;

						}while ( !(wall_win =='s' || wall_win== 'v') || ((winnings < 100 && wall_win =='v')));
						//*makes sure that there is at least 100kr in winnings other wise they have to choose 's'*//

				
					if (wall_win == 's')
					{
						cout << endl; 
						cout << "--------------------------------------------------------------" << endl;
						cout << "Du kan satsa upp till n\x84rmsta v\x84rdet avrundat ned\x86t." << endl;
						cout << "--------------------------------------------------------------" << endl << endl;
						
							
							//* a loop untill right input within requirements *//
							do {
								cout << "##############################################" << endl;
								cout << "# Du har " << wallet << "kr att spela f\x94r." << endl;
								cout << "##############################################" << endl << endl;

								cout << "Vill du satsa 100, 300 eller 500kr ?" << endl << endl << "Skriv hela v\x84rdet: ";
									cin >> bet;
									cout << endl;

								//*stops inf loop if a charecter is writen*//
								cin.clear();
								cin.ignore(numeric_limits <streamsize>::max(), '\n');
								
							} while (!(bet == 100 || bet == 300 || bet == 500) || (bet > wallet));
							 

						wallet = wallet - bet; 

						cout << "#############################################################" << endl;
						cout << "# Det \x86terst\x86r " << wallet << "kr p\x86 ditt spelkonto." << endl;
						cout << "#############################################################" << endl << endl << endl;

						cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl << endl;
						cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl << endl;
					}

					else if (wall_win == 'v')
					{

						cout << "Du kan satsa upp till n\x84rmsta v\x84rdet avrundat ned\x86t." << endl;


							//* a loop untill right input within requirements *//
						do {
							cout << "################################################" << endl;
							cout << "# Du har " << winnings << "kr att spela f\x94r." << endl << endl;
							cout << "################################################" << endl;

							cout << "Vill du satsa 100, 300 eller 500kr ?" << endl << endl << "Skriv hela v\x84rdet: ";
								cin >> bet;
								cout << endl;


							//*stops inf loop if a charecter is writen*//
							cin.clear();
							cin.ignore(numeric_limits <streamsize>::max(), '\n');

							
						} while (!(bet == 100 || bet == 300 || bet == 500) && (bet > winnings));


						winnings = winnings - bet;

						cout << "############################################################" << endl;
						cout << "# Det \x86terst\x86r " << winnings << "kr av vinstpengarna." << endl << endl; 
						cout << "############################################################" << endl << endl << endl;

						cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl << endl;
						cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl << endl;

					}

					int dice1=0, dice2=0, dice3=0, dice4=0, totthrow = 0;
					

					//* Start of dice throwing *// //* loops untill ether 2 wins or 3 throws *//

						for (int throws = 0; throws < 3 ; throws++ )
						{
											
								do {
																
									//*random generation 

									dice1 = rand() % 6 + 1;
									dice2 = rand() % 6 + 1;
									dice3 = rand() % 6 + 1;
									dice4 = rand() % 6 + 1;
									

									totthrow++;

									if  ((dice1 == dice3 && dice2 == dice4) || (dice1 == dice4 && dice2 == dice3))
										
									{
										
										cout << "Resultaten av kastet: " << endl << endl;
										cout << "_____________________" << endl << endl;
										
										cout << "Dina t\x84rningar: " << dice1 << ' ' << dice2 << endl;
										cout << "Datorns t\x84rningart: " << dice3 << ' ' << dice4 << endl << endl;
										
										cout << "Kastet blev oavgjort, vi kastar om.." << endl << endl;;

										cout << "-----------------------------" << endl << endl;
										
										totthrow--;
									}

								} while (((dice1 == dice3 && dice2 == dice4) || (dice1 == dice4 && dice2 == dice3)));

								
							

									cout << "Resultaten av kasten: " << endl;
									cout << "_____________________" << endl;

									cout << "Dina t\x84rningar: " << dice1 << ' ' << dice2 << endl;
									cout << "Datorns t\x84rningart: " << dice3 << ' ' << dice4 << endl << endl;
								

																	       
										//*resoults if "dice1" is highest*//
										if (dice1 > dice2)
										{ 
											if (dice3 > dice4)
											{
												if (dice1 > dice3)
												{

													cout << "-----------------------------" << endl;
													cout << "-Grattis du vann detta kast!-" << endl;
													cout << "-----------------------------" << endl << endl;

													userWonRound++;

												} 

												if (dice1 < dice3)
												{
													cout << "----------------------------------------" << endl;
													cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
													cout << "----------------------------------------" << endl << endl;

													compWonRound++;

												}

												if (dice1 == dice3)
												{
													if ((dice1 + dice2) > (dice3 + dice4))
													{
														cout << "-----------------------------" << endl;
														cout << "-Grattis du vann detta kast!-" << endl;
														cout << "-----------------------------" << endl << endl;

														userWonRound++;

													}
													if ((dice1 + dice2) < (dice3 + dice4))
													{
														cout << "----------------------------------------" << endl;
														cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
														cout << "----------------------------------------" << endl << endl;
														compWonRound++;
													}
												}
											}

											if (dice3 < dice4)
											{
												if (dice1 > dice4)
												{

													cout << "-----------------------------" << endl;
													cout << "-Grattis du vann detta kast!-" << endl;
													cout << "-----------------------------" << endl << endl;
													userWonRound++;

												}

												if (dice1 < dice4)
												{
													cout << "----------------------------------------" << endl;
													cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
													cout << "----------------------------------------" << endl << endl;
													compWonRound++;
												}

												if (dice1 == dice4)
												{
													if ((dice1 + dice2) > (dice3 + dice4))
													{
														cout << "-----------------------------" << endl;
														cout << "-Grattis du vann detta kast!-" << endl;
														cout << "-----------------------------" << endl << endl;
														userWonRound++;

													}
													if ((dice1 + dice2) < (dice3 + dice4))
													{
														cout << "----------------------------------------" << endl;
														cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
														cout << "----------------------------------------" << endl << endl;
														compWonRound++;

													}
												}
											}

											if (dice3 == dice4) 
											{
												if (dice1 > dice4)
												{
													cout << "-----------------------------" << endl;
													cout << "-Grattis du vann detta kast!-" << endl;
													cout << "-----------------------------" << endl << endl;
													userWonRound++;
												}
												if (dice1 < dice4)
												{
													cout << "----------------------------------------" << endl;
													cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
													cout << "----------------------------------------" << endl << endl;
													compWonRound++;

												}
												if (dice1 == dice4)
												{
													if ((dice1 + dice2) > (dice3 + dice4))
													{
														cout << "-----------------------------" << endl;
														cout << "-Grattis du vann detta kast!-" << endl;
														cout << "-----------------------------" << endl << endl;
														userWonRound++;
													}
													if ((dice1+dice2)< (dice3+dice4))
													{
														cout << "----------------------------------------" << endl;
														cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
														cout << "----------------------------------------" << endl << endl;
														compWonRound++;
													}

												}

											}

										}
										//*resoults if "dice 2" is highest*//
										if (dice1 < dice2)
										{	
											if (dice3 > dice4) 
											{
												if (dice2 > dice3)
												{
													cout << "-----------------------------" << endl;
													cout << "-Grattis du vann detta kast!-" << endl;
													cout << "-----------------------------" << endl << endl;

													userWonRound++;
												}

												if (dice2 < dice3)
												{
													cout << "----------------------------------------" << endl;
													cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
													cout << "----------------------------------------" << endl << endl;
													compWonRound++;
												}

												if (dice2 == dice3)
												{
													if ((dice1 + dice2) > (dice3 + dice4))
													{
														cout << "-----------------------------" << endl;
														cout << "-Grattis du vann detta kast!-" << endl;
														cout << "-----------------------------" << endl << endl;
														userWonRound++;
													}

													if ((dice1 + dice2) < (dice3 + dice4))
													{
														cout << "----------------------------------------" << endl;
														cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
														cout << "----------------------------------------" << endl << endl;
														compWonRound++;
													}
												}
											}

											if (dice3 < dice4)
											{
												if (dice2 > dice4)
												{

													cout << "-----------------------------" << endl;
													cout << "-Grattis du vann detta kast!-" << endl;
													cout << "-----------------------------" << endl << endl;
													userWonRound++;

												}

												if (dice2 < dice4)
												{
													cout << "----------------------------------------" << endl;
													cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
													cout << "----------------------------------------" << endl << endl;
													compWonRound++;

												} 

												if (dice2 == dice4)
												{
													if ((dice1 + dice2) > (dice3 + dice4))
													{
														cout << "-----------------------------" << endl;
														cout << "-Grattis du vann detta kast!-" << endl;
														cout << "-----------------------------" << endl << endl;

													}

													if ((dice1 + dice2) < (dice3 + dice4))
													{
														cout << "----------------------------------------" << endl;
														cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
														cout << "----------------------------------------" << endl << endl;
														compWonRound++;

													}
												}
											} 

											if (dice3 == dice4)
											{
												if (dice2 > dice4)
												{

													cout << "-----------------------------" << endl;
													cout << "-Grattis du vann detta kast!-" << endl;
													cout << "-----------------------------" << endl << endl;
													userWonRound++;

												}

												if (dice2 < dice4)
												{
													cout << "----------------------------------------" << endl;
													cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
													cout << "----------------------------------------" << endl << endl;
													compWonRound++;

												}

												if (dice2 == dice4)
												{
													if ((dice1 + dice2) > (dice3 + dice4))
													{
														cout << "-----------------------------" << endl;
														cout << "-Grattis du vann detta kast!-" << endl;
														cout << "-----------------------------" << endl << endl;
														userWonRound++;

													}

													if ((dice1 + dice2) < (dice3 + dice4))
													{
														cout << "----------------------------------------" << endl;
														cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
														cout << "----------------------------------------" << endl << endl;
														compWonRound++;

													}
												}
											}
										}

										if (dice1 == dice2)
										{
											if (dice3 > dice4)
											{
												if (dice1 > dice3)
												{

													cout << "-----------------------------" << endl;
													cout << "-Grattis du vann detta kast!-" << endl;
													cout << "-----------------------------" << endl << endl;

													userWonRound++;

												}

												if (dice1 < dice3)
												{
													cout << "----------------------------------------" << endl;
													cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
													cout << "----------------------------------------" << endl << endl;

													compWonRound++;

												}

												if (dice1 == dice3)
												{
													if ((dice1 + dice2) > (dice3 + dice4))
													{
														cout << "-----------------------------" << endl;
														cout << "-Grattis du vann detta kast!-" << endl;
														cout << "-----------------------------" << endl << endl;
														userWonRound++;

													}
													if ((dice1 + dice2) < (dice3 + dice4))
													{
														cout << "----------------------------------------" << endl;
														cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
														cout << "----------------------------------------" << endl << endl;

														compWonRound++;
													}
												}
											}

											if (dice3 < dice4)
											{
												if (dice1 > dice4)
												{

													cout << "-----------------------------" << endl;
													cout << "-Grattis du vann detta kast!-" << endl;
													cout << "-----------------------------" << endl << endl;
													userWonRound++;

												}

												if (dice1 < dice4)
												{
													cout << "----------------------------------------" << endl;
													cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
													cout << "----------------------------------------" << endl << endl;
													compWonRound++;
												}

												if (dice1 == dice4)
												{
													if ((dice1 + dice2) > (dice3 + dice4))
													{
														cout << "-----------------------------" << endl;
														cout << "-Grattis du vann detta kast!-" << endl;
														cout << "-----------------------------" << endl << endl;
														userWonRound++;

													}
													if ((dice1 + dice2) < (dice3 + dice4))
													{
														cout << "----------------------------------------" << endl;
														cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
														cout << "----------------------------------------" << endl << endl;
														compWonRound++;
													}
												}
											}

											if (dice3 == dice4)
											{

												if (dice2 > dice4)
													{

													cout << "-----------------------------" << endl;
													cout << "-Grattis du vann detta kast!-" << endl;
													cout << "-----------------------------" << endl << endl;
													userWonRound++;

												}

												if (dice2 < dice4)
												{
													cout << "----------------------------------------" << endl;
													cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
													cout << "----------------------------------------" << endl << endl;
													compWonRound++;

												}

												if (dice2 == dice4)
												{
													if ((dice1 + dice2) > (dice3 + dice4))
													{
														cout << "-----------------------------" << endl;
														cout << "-Grattis du vann detta kast!-" << endl;
														cout << "-----------------------------" << endl << endl;
														userWonRound++;

													}

													if ((dice1 + dice2) < (dice3 + dice4))
													{
														cout << "----------------------------------------" << endl;
														cout << "-Tyv\x84rr f\x94rlorade du detta kast..-" << endl;
														cout << "----------------------------------------" << endl << endl;
														compWonRound++;

													}
												}
												
											}
										}
													
										
								

								//* game winner has been decided *//
								if ((userWonRound == 2 || compWonRound == 2) || throws == 3)
								{
									//* player lost *//
									if (compWonRound == 2)
									{
										cout << "///////////////////////////////////////////////////////////////////" << endl;
										cout << "/   Tyv\x84rr vann datorn denna omg\x86ng.. b\x84ttre lycka n\x84sta g\x86ng!    /" << endl << endl;
										cout << "///////////////////////////////////////////////////////////////////" << endl << endl;
										cout << "======================================" << endl; 
										cout << "Det kastades totalt " << totthrow << " kast" << endl; 
										cout << "======================================" << endl;

										cout << "Du vann: " << userWonRound << " kast" << endl; 
										cout << "Datorn vann " << compWonRound << " kast " << endl << endl;

										cout << "#############################" << endl;
										cout << "# Pengar du kan spela f\x94r:#" << endl;
										cout << "#############################" << endl << endl;
										cout << "#############################" << endl;
										cout << "# Vinstpengar: " << winnings << endl;
										cout << "# Spelkonto: " << wallet << endl << endl;
										cout << "#############################" << endl << endl;
										break;
									}

									//* player won *//
									else if (userWonRound == 2 ) 
									{
											//*if winnings were used, "puts back" the bet, and adds winnings *// 
											if (wall_win == 'v')
											{
												winnings = bet*2 + winnings;
											}
											//* puts back the bet, and adds winnings *//
											if (wall_win == 's')
											{
												wallet = bet + wallet;
												winnings = bet + winnings;
											}

										
										

										cout << "//////////////////////////////////" << endl;
										cout << "/  Grattis du vann denna omg\x86ng! /" << endl;
										cout << "//////////////////////////////////" << endl << endl;

										cout << "#######################" << endl;
										cout << "# Din vinst: " << bet << endl;
										cout << "#######################" << endl << endl;
										 
										cout << "======================================" << endl;
										cout << "Det kastades totalt " << totthrow << " kast" << endl;
										cout << "======================================" << endl;

										cout << "Du vann: " << userWonRound << " kast" << endl;
										cout << "Datorn vann " << compWonRound << " kast " << endl << endl;
										
										cout << "#############################" << endl;
										cout << "#Pengar du kan spela f\x94r: # " << endl;
										cout << "#############################" << endl << endl;
										cout << "#############################" << endl;
										cout << "Vinstpengar: " << winnings << endl;
										cout << "Spelkonto: " << wallet << endl << endl;
										cout << "#############################" << endl << endl;

										break;
									}



								}

						}

					
				do 
				{
					cout << "-------------------------------------------------------------" << endl;
					cout << "Vill du spela en omg\x86ng till?" << endl << "Ja(j) Nej(n): ";
					cin >> yes_no;
					cout << endl << endl;

				} while (!(yes_no == 'n' || yes_no == 'j'));

				if (yes_no == 'n')
				{
					cout << "Du vann:" << winnings << endl; 

					cout << "*******************"<< endl;
					cout << "* V\x84lkommen \x86ter! *" << endl;
					cout << "*******************" << endl;

					return 0;
					//game ends 
				}

				/*if they chose j, the game restarts from the question if they want to use winnings*/
		} 

}





