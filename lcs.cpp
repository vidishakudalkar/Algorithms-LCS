#include <iostream>

using namespace std;

//Function to find max of 2 numbers
int max(int x, int y)
{
    if(x>=y)
      return x;
    else
      return y;
}

int main()
{
  string seq1,seq2;
  int len1,len2;
  int i,j;

  cout << "Enter the first sequence "; //User input string 1
  cin >> seq1;
 
  cout << "Enter the second sequence "; //User input string 2
  cin >> seq2;
  
  //finding lengths of strings
  len1 = seq1.length();
  len2 = seq2.length();
  
  //defining table
  int table[len1+1][len2+1] ={0};

  //Initialize 1st column as 0
  for(i=0;i<=len1;i++)
    table[i][0] =0;
  
  ////Initialize 1st row as 0
  for(i=0;i<=len2;i++)
    table[0][i] =0;
    
  for(i=1;i<=len1;i++)
    {
      for(j=1;j<=len2;j++)
      {
        if(seq1[i-1] == seq2[j-1]) //if character match
        {
          table[i][j]= table[i-1][j-1]+1; //last match + 1
        }
        else{
          table[i][j] = max(table[i-1][j],table[i][j-1]); //if character doesnt match then take max of left and top cell
        }
      }
    }
    
  //display table

  for(i=0;i<=len1;i++)
    {
      for(j=0;j<=len2;j++)
      {  
        cout << table[i][j] << "\t";
      }
      cout<<endl;
    }
    
  //Backtracking
 
  int array[50];
  i=len1;
  j=len2;
  int index = 1;
  
  while(i>0 && j>0)
  {

    if(table[i][j]!=table[i-1][j] && table[i][j]!=table[i][j-1]) //character match
    {
      array[index]=i;
      j--;
      i--;
      index++;

    }
    else if(table[i][j] == table[i-1][j]) //entry taken from top cell
    {
      i--;  
    }
    else if(table[i][j] == table[i][j-1]) //entry taken from left cell
    {
      j--;
    }
  }
  
  //printing LCS
  

  if(index == 1)
	{
		cout << "No LCS";
	}
  else
  {
    cout<< "LCS ";
    for(int i=index-1;i>0;i--) {
        
        cout << seq1[array[i]-1];
    }
  }
  
  
  
    return 0;
}
