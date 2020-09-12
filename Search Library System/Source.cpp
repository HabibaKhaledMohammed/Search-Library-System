#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include<fstream>
#include<conio.h>

using namespace std;
// store word and its position 
struct library{
	string word;
	unsigned long long int* position = new unsigned long long int[10000];
};
// store name of the book  and  the number of the wanted word found in
struct bookWordC{
	string name;
	int counter;
};
//display introduction
void forum();
// choose  catageory
void swiFun();
//display catageory 
void inputCatageory(char &catageory);
// declaration of funtion that display catageory of history 
void inputHistory(char &);
// declaration of funtion that display catogeory of novel 
void inputNovel(char &);
//declaration of funtion that display catagrory of science 
void inputScience(char &);
// declaration of funtion that findout if the user input one word or two and return one or two 
int input(string &search1, string &search2);
//declaration of funtion that find word or two words in the book 
int booksCut(string search1, string file, library& x, library &y, int numOfSearch, string search2, int &counter1, int &counter2);
//declaration of funtion that display repated of word in the book with descending order
void mySort(bookWordC[], int n);

int main()
{
	forum();
	swiFun();
	return 0;
}
void forum(){
	//background is grey and words are yellow 
	system("title Search Library System");
	system("Color 8e");
	cout << "                      #######################################################################\n";
	cout << "                      #######################################################################\n\n";
	cout << "                      ################       ^_^ library search  system ^_^  ################\n\n";
	cout << "                      #######################################################################\n";
	cout << "                      #######################################################################\n\n\n";
	cout << "                                                   PLEASE, PRESS ENTER";
	char button;
	button = _getch();
	// display catageory while button ==newline
	while (button != '\r')
	{
		button = _getch();

	}
	// clear anything up
	system("cls");

}
void swiFun(){
	fstream file;
	string search1, search2;
	int numOfSearch;
	char catageory;

	//calling input catageory.
	inputCatageory(catageory);

	char history, novel, science, scienceFiction, kids;

	//switch main catageory
	switch (catageory)
	{
		//switch history catageory.
	case 'H':
	case 'h':
		system("cls");
		//switch history of egypt.
		inputHistory(history);  //calling history function 
		switch (history){
		case'E'://egypt
		case'e':
			system("cls");
			cout << "PLEASE, ENTER word YOU want to search : ";
			numOfSearch = input(search1, search2); //calling input function 
			system("cls");
			{
				bookWordC egypt[5];
				int n = 5, number = 0;

				//repated of word one and word two
				int counter1, counter12;
				library book1, book12;
				string f = "an egyptain princess(history).txt";
				egypt[0].counter = booksCut(search1, f, book1, book12, numOfSearch, search2, counter1, counter12);
				egypt[0].name = "an egyptain princess";

				int counter2, counter22;
				library book2, book22;
				f = "history of egypt(history).txt";
				egypt[1].counter = booksCut(search1, f, book2, book22, numOfSearch, search2, counter2, counter22);
				egypt[1].name = "history of egypt";

				int counter3, counter32;
				library book3, book32;
				f = "peeps at many lands(history).txt";
				egypt[2].counter = booksCut(search1, f, book3, book32, numOfSearch, search2, counter3, counter32);
				egypt[2].name = "peeps at many lands";

				int counter4, counter42;
				library book4, book42;
				f = "pharos the egyptian(history).txt";
				egypt[3].counter = booksCut(search1, f, book4, book42, numOfSearch, search2, counter4, counter42);
				egypt[3].name = "pharos the egyptian";
				f = "treasury of ancient egypt(history).txt";

				int counter5, counter52;
				library book5, book52;
				egypt[4].counter = booksCut(search1, f, book5, book52, numOfSearch, search2, counter5, counter52);
				egypt[4].name = "treasury of ancient egypt";
				//call to funtion of sort
				mySort(egypt, n);

				for (int i = 0; i < 5; i++)
				if (egypt[i].counter>0)
					number++;
				cout << "The number of books contain that word is : " << number << endl;

				for (int i = 0; i < 5; i++)
				if (egypt[i].counter>0)
					cout << egypt[i].counter << "\t" << egypt[i].name << endl;
			}
			break;

			//history of london catageory.
		case'L'://london
		case'l':
			system("cls");
			cout << "PLEASE, ENTER word YOU want to search : ";
			numOfSearch = input(search1, search2);
			system("cls");
			{
				bookWordC london[5];
				int n = 5, number = 0;

				int counter1, counter12;
				library book1, book12;
				string f = "history of london.txt";
				london[0].counter = booksCut(search1, f, book1, book12, numOfSearch, search2, counter1, counter12);
				london[0].name = "history of london";

				int counter2, counter22;
				library book2, book22;
				f = "life in london.txt";
				london[1].counter = booksCut(search1, f, book2, book22, numOfSearch, search2, counter2, counter22);
				london[1].name = "life in london";

				int counter3, counter32;
				library book3, book32;
				f = "london in1731.txt";
				london[2].counter = booksCut(search1, f, book3, book32, numOfSearch, search2, counter3, counter32);
				london[2].name = "london in1731";

				int counter4, counter42;
				library book4, book42;
				f = "london pride.txt";
				london[3].counter = booksCut(search1, f, book4, book42, numOfSearch, search2, counter4, counter42);
				london[3].name = "london pride";

				int counter5, counter52;
				library book5, book52;
				f = "London's underworld.txt";
				london[4].counter = booksCut(search1, f, book5, book52, numOfSearch, search2, counter5, counter52);
				london[4].name = "London's underworld";
				//call to funtion of sort
				mySort(london, n);

				for (int i = 0; i < 5; i++)
				if (london[i].counter>0)//if counter equal zero
					number++;
				cout << "The number of books contain that word is : " << number << endl;

				for (int i = 0; i < 5; i++)
				if (london[i].counter>0)//if counter =0
					cout << london[i].counter << "  " << london[i].name << "\n";
			}
			break;

		default:
			system("cls");
			cout << "THIS CATAGEORY DOESNOT EXIST!!!\n";
		}
		break;

		// novels catageory.
	case 'N':
	case 'n':
		system("cls");
		inputNovel(novel);
		switch (novel){
		case'S':   // s for Shakespeare's novels 
		case's':
			system("cls");
			cout << "PLEASE, ENTER word YOU want to search : ";
			numOfSearch = input(search1, search2);
			system("cls");
			{
				bookWordC shakespeare[3];
				int n = 3, number = 0;

				int counter1, counter12;
				library book1, book12;
				string f = "Twelfth Night.txt";
				shakespeare[0].counter = booksCut(search1, f, book1, book12, numOfSearch, search2, counter1, counter12);
				shakespeare[0].name = "Twelfth Night";

				int counter2, counter22;
				library book2, book22;
				f = "Hamlet.txt";
				shakespeare[1].counter = booksCut(search1, f, book2, book22, numOfSearch, search2, counter2, counter22);
				shakespeare[1].name = "Hamlet";

				int counter3, counter32;
				library book3, book32;
				f = "As You Like It.txt";
				shakespeare[2].counter = booksCut(search1, f, book3, book32, numOfSearch, search2, counter3, counter32);
				shakespeare[2].name = "As You Like It";
				//call to funtion of sort
				mySort(shakespeare, n);
				for (int i = 0; i < 3; i++)
				if (shakespeare[i].counter>0)
					number++;
				cout << "The number of books contain that word is : " << number << endl;

				for (int i = 0; i < 3; i++)
				if (shakespeare[i].counter>0)
					cout << shakespeare[i].counter << "\t" << shakespeare[i].name << endl;

			}
			break;

		case'C': // c for Charles dickens's novels
		case'c':
			system("cls");
			cout << "PLEASE, ENTER word YOU want to search : ";
			numOfSearch = input(search1, search2);
			system("cls");
			{
				bookWordC charles[3];
				int n = 3, number = 0;

				int counter1, counter12;
				library book1, book12;
				string f = "Great Expeactations.txt";
				charles[0].counter = booksCut(search1, f, book1, book12, numOfSearch, search2, counter1, counter12);
				charles[0].name = "Great Expeactations";

				int counter2, counter22;
				library book2, book22;
				f = "The Mystery of Edwin Drood.txt";
				charles[1].counter = booksCut(search1, f, book2, book22, numOfSearch, search2, counter2, counter22);
				charles[1].name = "The Mystery of Edwin Drood";

				int counter3, counter32;
				library book3, book32;
				f = "Three Ghost Stories.txt";
				charles[2].counter = booksCut(search1, f, book3, book32, numOfSearch, search2, counter3, counter32);
				charles[2].name = "Three Ghost Stories";
				//call to funtion of sort
				mySort(charles, n);
				for (int i = 0; i < 3; i++)
				if (charles[i].counter>0)
					number++;
				cout << "The number of books contain that word is : " << number << endl;
				for (int i = 0; i < 3; i++)
				if (charles[i].counter>0)//if counter isnot equal zero
					cout << charles[i].counter << "\t" << charles[i].name << endl;

			}

			break;
		case'M': // m for Makepeace's novels
		case'm':
			system("cls");
			cout << "PLEASE, ENTER word YOU want to search : ";
			numOfSearch = input(search1, search2);
			system("cls");
			{
				bookWordC makepeace[3];
				int n = 3, number = 0;

				int counter1, counter12;
				library book1, book12;
				string f = "Henry Esmond.txt";
				makepeace[0].counter = booksCut(search1, f, book1, book12, numOfSearch, search2, counter1, counter12);
				makepeace[0].name = "Henry Esmond";

				int counter2, counter22;
				library book2, book22;
				f = "The History of Pendennis.txt";
				makepeace[1].counter = booksCut(search1, f, book2, book22, numOfSearch, search2, counter2, counter22);
				makepeace[1].name = "The History of Pendennis";

				int counter3, counter32;
				library book3, book32;
				f = "Vanity Fair.txt";
				makepeace[2].counter = booksCut(search1, f, book3, book32, numOfSearch, search2, counter3, counter32);
				makepeace[2].name = "Vanity Fair";

				mySort(makepeace, n);
				for (int i = 0; i < 3; i++)
				if (makepeace[i].counter>0)
					number++;
				cout << "The number of books contain that word is : " << number << endl;
				for (int i = 0; i < 3; i++)
				if (makepeace[i].counter>0)
					cout << makepeace[i].counter << "\t" << makepeace[i].name << endl;

			}

			break;
		case'O': // for other writers novels 
		case'o':
			system("cls");
			cout << "PLEASE, ENTER word YOU want to search : ";
			numOfSearch = input(search1, search2);
			system("cls");
			{
				bookWordC others[3];
				int n = 3, number = 0;

				int counter1, counter12;
				library book1, book12;
				string f = "LORD OF THE FLIES.txt";
				others[0].counter = booksCut(search1, f, book1, book12, numOfSearch, search2, counter1, counter12);
				others[0].name = "LORD OF THE FLIES";

				int counter2, counter22;
				library book2, book22;
				f = "Stranger.txt";
				others[1].counter = booksCut(search1, f, book2, book22, numOfSearch, search2, counter2, counter22);
				others[1].name = "Stranger";

				int counter3, counter32;
				library book3, book32;
				f = "war and peace.txt";
				others[2].counter = booksCut(search1, f, book3, book32, numOfSearch, search2, counter3, counter32);
				others[2].name = "war and peace";

				mySort(others, n);
				for (int i = 0; i < 5; i++)
				if (others[i].counter>0)
					number++;
				cout << "The number of books contain that word is : " << number << endl;
				for (int i = 0; i < 3; i++)
				if (others[i].counter>0)
					cout << others[i].counter << "\t" << others[i].name << endl;

			}

			break;

		default:
			system("cls");
			cout << "THIS CATAGEORY DOESNOT EXIST!!!\n";
		}
		break;
	case 'S': //for science books 
	case 's':
		system("cls");
		inputScience(science);
		switch (science){
		case'P': // for programing books 
		case'p':
			cout << "PLEASE, ENTER word YOU want to search : ";
			numOfSearch = input(search1, search2);
			system("cls");
			{
				bookWordC programming[3];
				int n = 3, number = 0;

				int counter1, counter12;
				library book1, book12;
				string f = "clean code .txt";
				programming[0].counter = booksCut(search1, f, book1, book12, numOfSearch, search2, counter1, counter12);
				programming[0].name = "clean code";

				int counter2, counter22;
				library book2, book22;
				f = "code complete .txt";
				programming[1].counter = booksCut(search1, f, book2, book22, numOfSearch, search2, counter2, counter22);
				programming[1].name = "code complete";

				int counter3, counter32;
				library book3, book32;
				f = "introduction to algorithms.txt";
				programming[2].counter = booksCut(search1, f, book3, book32, numOfSearch, search2, counter3, counter32);
				programming[2].name = "introduction to algorithms";

				mySort(programming, n);
				for (int i = 0; i < 3; i++)
				if (programming[i].counter>0)
					number++;
				cout << "The number of books contain that word is : " << number << endl;
				for (int i = 0; i < 3; i++)
				if (programming[i].counter>0)
					cout << programming[i].counter << "\t" << programming[i].name << endl;

			}

			break;
		case'B': // for Biology books 
		case'b':
			system("cls");
			cout << "PLEASE, ENTER word YOU want to search : ";
			numOfSearch = input(search1, search2);
			system("cls");
			{
				bookWordC biology[3];
				int n = 3, number = 0;

				int counter1, counter12;
				library book1, book12;
				string f = "encyclopedia of biology.txt";
				biology[0].counter = booksCut(search1, f, book1, book12, numOfSearch, search2, counter1, counter12);
				biology[0].name = "encyclopedia of biology";

				int counter2, counter22;
				library book2, book22;
				f = "methods in molecular biology.txt";
				biology[1].counter = booksCut(search1, f, book2, book22, numOfSearch, search2, counter2, counter22);
				biology[1].name = "methods in molecular biology";

				int counter3, counter32;
				library book3, book32;
				f = "plant cell culture protocols.txt";
				biology[2].counter = booksCut(search1, f, book3, book32, numOfSearch, search2, counter3, counter32);
				biology[2].name = "plant cell culture protocols";

				mySort(biology, n);
				for (int i = 0; i < 3; i++)
				if (biology[i].counter>0)
					number++;
				cout << "The number of books contain that word is : " << number << endl;
				for (int i = 0; i < 3; i++)
				if (biology[i].counter>0)
					cout << biology[i].counter << "\t" << biology[i].name << endl;
			}

			break;
		case'C': // for Calculus books 
		case'c':
			system("cls");
			cout << "PLEASE, ENTER word YOU want to search : ";
			numOfSearch = input(search1, search2);
			system("cls");
			{
				bookWordC calculus[3];
				int n = 3, number = 0;

				int counter1, counter12;
				library book1, book12;
				string f = "calculus and analytic geometry.txt";
				calculus[0].counter = booksCut(search1, f, book1, book12, numOfSearch, search2, counter1, counter12);
				calculus[0].name = "calculus and analytic geometry";

				int counter2, counter22;
				library book2, book22;
				f = "introduction to calculus.txt";
				calculus[1].counter = booksCut(search1, f, book2, book22, numOfSearch, search2, counter2, counter22);
				calculus[1].name = "introduction to calculus";

				int counter3, counter32;
				library book3, book32;
				f = "single variable calculus.txt";
				calculus[2].counter = booksCut(search1, f, book3, book32, numOfSearch, search2, counter3, counter32);
				calculus[2].name = "single variable calculus";

				mySort(calculus, n);
				for (int i = 0; i < 3; i++)
				if (calculus[i].counter>0)
					number++;
				cout << "The number of books contain that word is : " << number << endl;
				for (int i = 0; i < 3; i++)
				if (calculus[i].counter>0)
					cout << calculus[i].counter << "\t" << calculus[i].name << endl;
			}

			break;
		case'S': // for Space & Physics books 
		case's':
			system("cls");
			cout << "PLEASE, ENTER word YOU want to search : ";
			numOfSearch = input(search1, search2);
			system("cls");
			{
				bookWordC space[3];
				int n = 3, number = 0;

				int counter1, counter12;
				library book1, book12;
				string f = "psychology of space exploration.txt";
				space[0].counter = booksCut(search1, f, book1, book12, numOfSearch, search2, counter1, counter12);
				space[0].name = "psychology of space exploration";

				int counter2, counter22;
				library book2, book22;
				f = "radioisotope and nuclear technologies for space exploration.txt";
				space[1].counter = booksCut(search1, f, book2, book22, numOfSearch, search2, counter2, counter22);
				space[1].name = "radioisotope and nuclear technologies for space exploration";

				int counter3, counter32;
				library book3, book32;
				f = "topology in physics.txt";
				space[2].counter = booksCut(search1, f, book3, book32, numOfSearch, search2, counter3, counter32);
				space[2].name = "topology in physics";

				mySort(space, n);
				for (int i = 0; i < 3; i++)
				if (space[i].counter>0)
					number++;
				cout << "The number of books contain that word is : " << number << endl;
				for (int i = 0; i < 3; i++)
				if (space[i].counter>0)
					cout << space[i].counter << "\t" << space[i].name << endl;
			}

			break;
		default:
			system("cls");
			cout << "THIS CATAGEORY DOESNOT EXIST!!!";
		}

		break;
	case 'F':
	case 'f':
		system("cls");
		cout << "PLEASE, ENTER word YOU want to search : ";
		numOfSearch = input(search1, search2);
		system("cls");
		{
			bookWordC SciFi[10];
			int n = 10, number = 0;

			int counter1, counter12;
			library book1, book12;
			string f = "1984.txt";
			SciFi[0].counter = booksCut(search1, f, book1, book12, numOfSearch, search2, counter1, counter12);
			SciFi[0].name = "1984";

			int counter2, counter22;
			library book2, book22;
			f = "A Journey to the Centre of the Earth.txt";
			SciFi[1].counter = booksCut(search1, f, book2, book22, numOfSearch, search2, counter2, counter22);
			SciFi[1].name = "A Journey to the Centre of the Earth";

			int counter3, counter32;
			library book3, book32;
			f = "BRAVE NEW WORLD.txt";
			SciFi[2].counter = booksCut(search1, f, book3, book32, numOfSearch, search2, counter3, counter32);
			SciFi[2].name = "BRAVE NEW WORLD";

			int counter4, counter42;
			library book4, book42;
			f = "Dune.txt";
			SciFi[3].counter = booksCut(search1, f, book4, book42, numOfSearch, search2, counter4, counter42);
			SciFi[3].name = "Dune";

			int counter5, counter52;
			library book5, book52;
			f = "frankenstein.txt";
			SciFi[4].counter = booksCut(search1, f, book5, book52, numOfSearch, search2, counter5, counter52);
			SciFi[4].name = "frankenstein";

			int counter6, counter62;
			library book6, book62;
			f = "Stranger in a Strange Land.txt";
			SciFi[5].counter = booksCut(search1, f, book6, book62, numOfSearch, search2, counter6, counter62);
			SciFi[5].name = "Stranger in a Strange Land";

			int counter7, counter72;
			library book7, book72;
			f = "The Host.txt";
			SciFi[6].counter = booksCut(search1, f, book7, book72, numOfSearch, search2, counter7, counter72);
			SciFi[6].name = "The Host";

			int counter8, counter82;
			library book8, book82;
			f = "the hunger games.txt";
			SciFi[7].counter = booksCut(search1, f, book8, book82, numOfSearch, search2, counter8, counter82);
			SciFi[7].name = "the hunger games";

			int counter9, counter92;
			library book9, book92;
			f = "the martian.txt";
			SciFi[8].counter = booksCut(search1, f, book9, book92, numOfSearch, search2, counter9, counter92);
			SciFi[8].name = "the martian";

			int counter10, counter102;
			library book10, book102;
			f = "the time machine.txt";
			SciFi[9].counter = booksCut(search1, f, book10, book102, numOfSearch, search2, counter10, counter102);
			SciFi[9].name = "the time machine";
			//call funtion of sort
			mySort(SciFi, n);
			for (int i = 0; i < 10; i++)
			if (SciFi[i].counter>0)
				number++;
			cout << "The number of books contain that word is : " << number << endl;
			for (int i = 0; i < 10; i++)
			if (SciFi[i].counter>0)
				cout << SciFi[i].counter << "  " << SciFi[i].name << "\n";
		}

		break;

	case 'k':
	case 'K':
		system("cls");

		break;

	default:
		system("cls");
		cout << "ERROR!!!! NOT FOUND.";

	}


}
void inputCatageory(char &catageory){
	cout << "################# && ##################\n";
	cout << "# Please, select a catageory for :    #\n";
	cout << "# Histroy: H                          #\n";
	cout << "# Novel: N                            #\n";
	cout << "# Science: S                          #\n";
	cout << "# ScienceFiction: F                   #\n";
	cout << "# Kids: K                             #\n";
	cout << "#######################################\n";
	cout << "------->  ";
	cin >> catageory;

}
//  display catageory of history 
void inputHistory(char &history){
	cout << "################# && ##################\n";
	cout << "# Please, select catageory for:       #\n";
	cout << "# History of Egypt: E                 #\n";
	cout << "# History of London: L                #\n";
	cout << "################# && ##################\n";
	cout << "------->  ";
	cin >> history;
}
//display catageory of novel
void inputNovel(char &novel){
	cout << "################# && ####################\n";
	cout << "# Please, select catageory for:         #\n";
	cout << "# Shakespeare : S                       #\n";
	cout << "# Charles dickens: C                    #\n";
	cout << "# Makepeace: M                          #\n";
	cout << "# Others: O                             #\n";
	cout << "################# && ####################\n";
	cout << "------->  ";
	cin >> novel;
}
//display catageory of science
void inputScience(char &science){
	cout << "################# && ####################\n";
	cout << "#Please, select catageory for:          #\n";
	cout << "#Programming: P                         #\n";
	cout << "#Biology: B                             #\n";
	cout << "#Calculus: C                            #\n";
	cout << "#Space & Physics: S                     #\n";
	cout << "################# && ####################\n";
	cout << "------->  ";
	cin >> science;
}
// determine wether the user enter one word or two words 
int input(string &search1, string &search2){
	bool space = false;
	int counter = 1;
	string state;
	search1 = "";
	search2 = "";
	cin.ignore();
	getline(cin, state);
	for (int i = 0; i < state.size(); i++)
	{
		if (state[i] == ' ')
			space = true;
		//if user didn't enter space store the char (that the user entered ) in search1 and return  one
		else if (!space)
			search1 += state[i];
		//if user  entered space store the char (that the user entered ) in search2 return two
		else
		{
			search2 += state[i];
			counter = 2;
		}
	}
	return counter;
}

//find word or two words in the book and count them
int booksCut(string search1, string file, library &x, library &y, int numOfSearch, string search2, int &counter1, int &counter2)
{
	// if two words count of every one seperated
	counter1 = 0, counter2 = 0;
	int counter = 0;  //count number of the repated  search word 
	unsigned long long int  numOfWords1 = 100000;
	unsigned long long int num = 0; // count the position of every word in the file
	fstream file1;
	file1.open(file);
	string word // the word that the program  read from the book 
		, bspecial = "" //if there is a char isn't alphabet at   the end of the word 
		, fspecial = "" //if there is a char isn't alphabet  at the forward of the word
		, bword = "";   // store the small chars in the end 

	while (!file1.eof()){
		bspecial = "", fspecial = "", bword = "";
		file1 >> word; // read from the book 

		//return the word without the special chars  from forward
		while (!((word[0] >= 'a') && (word[0] <= 'z')) && !((word[0] >= 'A') && (word[0] <= 'Z')))
		{
			// if  it is  one char out from the loop
			if (word.size() == 1)
				break;

			fspecial = word;  // store the word at forward
			for (int i = 0; i < fspecial.size(); i++)
			{
				if (i != 0)
				{
					if (i == 1)
						word = fspecial[1];
					else
						word += fspecial[i];
				}
				if (i == fspecial.size() - 1)
					num++;
			}

		}

		//return the word without special chars the  from end 
		while (!((word[word.size() - 1] >= 'a') && (word[word.size() - 1] <= 'z')) && !((word[word.size() - 1] >= 'A') && (word[word.size() - 1] <= 'Z')))
		{
			if (word.size() == 1)
				break;

			bspecial = word;
			for (int i = 0; i < bspecial.size(); i++) // 
			{
				if (i != bspecial.size() - 1)
				if (i == 0)
					word = bspecial[0];
				else
					word += bspecial[i];
				else
				{
					bspecial = bspecial[bspecial.size() - 1];
					bword += bspecial[bspecial.size() - 1]; // store the special chars at the end of the word 

				}
			}

		}
		//if  one word
		if (numOfSearch == 1)
		{
			if (word == search1)
			{
				x.word = search1;
				x.position[counter] = num + 1;  // store word and position in  library x 
				counter++;
			}
		}


		//if two word
		else{
			if (word == search1)
			{
				x.word = search1;
				x.position[counter1] = num + 1;
				counter1++;
			}
			if (word == search2)
			{
				y.word = search2;
				y.position[counter2] = num + 1;
				if (y.position[counter2] == x.position[counter1 - 1] + 1)
					counter++;
				counter2++;
			}

		}

		num++;

		if (bword != "")
			num++;



	}
	//close file
	file1.close();


	return counter;

}

//  descending order of books 
void mySort(bookWordC x[], int n){
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n - 1; j++)
		{
			if (x[i].counter < x[j + 1].counter)
				swap(x[i], x[j + 1]);
		}
	}
}