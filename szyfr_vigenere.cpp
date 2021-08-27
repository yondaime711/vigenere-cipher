#include<iostream>
#include<string>
using namespace std; 


	string txt_g; 
	string klucz_g;

void wprowadzanie()
{
    string txt;
    cout<<"wprowadz tekst do zaszyfrowania: ";
    getline(cin,txt);
    
    
    for(int i=0;i<txt.length();i++)
    {
        txt[i]=toupper(txt[i]);
    }
    
    string klucz;
    cout<<"wprowadz klucz do zaszyfrowania: ";
    getline(cin,klucz);

    
    for(int i=0;i<klucz.length();i++)
    {
        klucz[i]=toupper(klucz[i]);
    }
    
    txt_g = txt;
    klucz_g = klucz;
    
}

string generuj(string txt, string klucz) 
{ 
	int x = txt.size(); 

	for (int i = 0; ; i++) 
	{ 
		if (x == i) 
			i = 0; 
		if (klucz.size() == txt.size()) 
			break; 
		klucz.push_back(klucz[i]); 
	} 
	return klucz; 
} 


string szyfruj(string txt, string klucz) 
{ 
	string szyfruj_txt; 
    
	for (int i = 0; i < txt.size(); i++) 
	{ 
	    if(txt[i] ==32)
	    {
            szyfruj_txt += 32;
	    }else
	    {
		int x = (txt[i] + klucz[i]) %26; 

		x += 'A'; 
		
		szyfruj_txt.push_back(x); 
	    }
	} 
	return szyfruj_txt; 
} 


string deszyfruj(string szyfruj_txt, string klucz) 
{ 
	string deszyfruj_txt; 

	for (int i = 0 ; i < szyfruj_txt.size(); i++) 
	{ 
	    if(szyfruj_txt[i] ==32){
        deszyfruj_txt += 32;
	    }else
	    {
		int x = (szyfruj_txt[i] - klucz[i] + 26) %26; 

		x += 'A'; 
		deszyfruj_txt.push_back(x); 
	    }
	} 
	return deszyfruj_txt; 
} 


int main() 
{ 
 
    wprowadzanie();
	string klucz_s = generuj(txt_g, klucz_g); 
	//sprawdzenie poprawnosci klucza
    //cout<<"klucz: "<<klucz_s<<endl;
	string szyfruj_txt = szyfruj(txt_g, klucz_s); 

	cout << "zaszyfrowany tekst: "<< szyfruj_txt << "\n"; 

	cout << "Deszyfrowany tekst: "<< deszyfruj(szyfruj_txt, klucz_s); 
	return 0; 
} 
