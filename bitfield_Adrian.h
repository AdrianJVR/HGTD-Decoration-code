#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

void decToBinary(uint32_t n)
{

  cout << "Summary info = " << n << endl;
  // Array to store binary number
	
  std::vector<int> binaryNum(32,0);
  string reco;
  string fall[8];
	
  // Counter for binary array
  int i = 0;
  while (n > 0) {
    // Storing remainder in binary
    // array
    binaryNum[i] = n % 2;
    n = n / 2;
    i++;
  }
	
  // Printing binary array in reverse
  // order
  for (int j = 31; j >= 0; j--){
    cout << binaryNum[j];
    cout << "";
  }
    cout << "" << endl;	
    //Generation of subparts:
	
  for(int i = 0; i <= 31; i=i+4){	
    for(int k = i; k <= i+3; k++){
      reco=to_string(binaryNum[k])+reco;
    }
    fall[i/4] = reco;
    reco = '\0';
  }

//Chart With the layers and summary information.
	
cout << "| Bit   |" << fall[7] + "        |" << fall[6] + "        |" << fall[5] + "       |" << fall[4] + "    |" << fall[3] + "       |" << fall[2] + "             |" << fall[1] + "      |" << fall[0]  + "     |" <<  endl;
cout << "| Size  |" << to_string(fall[7].size()-1) + "           |" << to_string(fall[6].size()-1) + "           |" << to_string(fall[5].size()-1) + "          |" <<  to_string(fall[4].size()-1) + "       |" << to_string(fall[3].size()-1) + "          |" << to_string(fall[2].size()-1) + "                |" << to_string(fall[1].size()-1) + "         |" << to_string(fall[0].size()) + "        |" << endl;
cout << "| Value |" << " Unassigned |" << " Unassigned |" << " Potential |" << " Primes |" << " ITk holes |" << " after time comp |" << " expected |" << " reco'ed |" << endl;	

/* 
  cout << "" << endl;
  bool a =false;
  for (int i=0; i<=3; i++){
    if (binaryNum[i]==1){
    cout << "For the reco'ed. There's a hit in the layer " << i << endl; 
    a = true;
    }
  }
  if (a==false){cout << "There's no hits in the layers." << endl;}
  cout << boolalpha; 
  cout << a << endl;
  a = false;
  for (int i=0; i<=3; i++){
    if (binaryNum[i+8]==1){
    cout << "The hit in the layer " << i << " has fulfilled the requirements." << endl; 
    a = true;
    }
    
  }
  if (a==false){cout << "No hit has fulfilled the requirements." << endl;}
  cout << a << endl;
  std::cout << "" << std::endl; */
};

//numberPotentialPrimaryHits()
int newNumberPotentialPrimaryHits(uint32_t n) {
  
  // Array to store binary number
  std::vector<int> binaryNumPH(32,0);
  
  int i = 0;
  while (n > 0) {
    // Storing remainder in binary
    // array
    binaryNumPH[i] = n % 2;
    n = n / 2;
    i++;
  }

  int nprimes=0;

  for (int l=0; l<=3; l++){
    if (binaryNumPH[l+20]==1){
    nprimes++;
    }
  }

  return nprimes;
};


bool newhasTime(uint32_t n)
{
  std::vector<int> binaryNumHT(32,0);
 
  // Counter for binary array
  int i = 0;
  while (n > 0) {
    // Storing remainder in binary
    // array
    binaryNumHT[i] = n % 2;
    n = n / 2;
    i++;
  }

  bool a = false;
  for (int j=0; j<=3; j++){
    if (binaryNumHT[j+8]==1){
    a = true;
    }
  }
 return a; 
};

float newfracPrimaryHits(uint32_t n) {
 
  int m = n;
  // Array to store binary number
  std::vector<int> binaryNumFPH(32,0);

  int i = 0;
  while (n > 0) {
    // Storing remainder in binary
    // array
    binaryNumFPH[i] = n % 2;
    n = n / 2;
    i++;
  }

  int nrecons=0;

  for (int l=0; l<=3; l++){
    if (binaryNumFPH[l+8]==1){
    nrecons++;
    }
  }

  int nprimary=0;

  for (int j=0; j<=3; j++){
    if (binaryNumFPH[j+16]==1){
    nprimary++;
    }
    
  }
  
  float fraction;
  
  if (not newhasTime(m)) {
     cout << "[TrackTimeAccTool::numberPotentialPrimaryHits]"
                    "Expected clusters not available, returning 0\n" << endl;
     return -999.;
  }

  fraction = (float)nprimary/(float)nrecons;   
  return fraction;
};

