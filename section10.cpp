#include <iostream>
#include <string>
using namespace std;

int main()
{
  string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
  string key {"qwertyuiopasdfghjklzxcvbnmMNBVCXZLKJHGFDSAPOIUYTREWQ"};
  string phrase;
  int option {0};
  size_t count_phrase {0};

  do {
  cout<<"Do you want to incrypt(1) or decrypt(0): ";
  cin>>option;
  }while(option != 0 && option != 1);

  switch (option) { //1 for incrypt / 0 for decrypt 
    case 1: //incrypt case
      cout<<"Insert the phrase to cipher: ";
      cin>>phrase;
      for(char letter_phrase: phrase) //for to loop through the phrase 1 by 1
      {
        size_t count_cipher {0};  //declaring count_cipher for the location of the key
        for(char letter_alphabet: alphabet) //for to loop through the alphabet
        {
          if(letter_phrase==letter_alphabet){ //if to verify the letter of the phrase with the alphabet to know its location by adding 1
            phrase.at(count_phrase)=key.at(count_cipher); //replacing the phrase with the key
          }
          count_cipher++; //updating the key location to match the alphabet
        }
        count_phrase++; //updating the phrase location by 1
        count_cipher = 0; //reseting the key location to 0
      }
      cout<<"Incrypted phrase: "<<phrase<<endl;
      break;
    case 0:
      cout<<"Insert the phrase to decrypt: ";
      cin>>phrase;
      for(char letter_phrase: phrase)
      {
        size_t count_cipher {0};
        for(char letter_cipher: key)
        {
          if(letter_phrase==letter_cipher){
            phrase.at(count_phrase)=alphabet.at(count_cipher);
          }
          count_cipher++;
        }
        count_phrase++;
        count_cipher = 0;
      }
      cout<<"Decrypted phrase: "<<phrase<<endl;
      break;
    default:
      cout<<"YOU SHOULD NEVER GET THIS OUTPUT";
      break;
  }

  /*for(auto test: alphabet)  output for debug purpose
      {
    cout<<test;
  }
  cout<<endl;
  for(auto test: key)
  {
    cout<<test;
  }*/

  return 0;
}
