/*************************************************************************************************************************************************************/
/*                                                    SAKARYA �N�VERS�TES�                                                                                   */
/*                                           B�LG�SAYAR VE B�L���M B�L�MLER� FAK�LTES�                                                                       */
/*                                                 B�LG�SAYAR M�HEND�SL��� B�L�M�                                                                            */
/*                                                PROGRAMLAMAYA G�R�� DERS�                                                                                  */
/*                                                         3. �DEV                                                                                           */
/*                                                      BEYZANUR DEM�R                                                                                        */
/*                                                        G161210045                                                                                          */
/*                                                         D GRUBU                                                                                            */
/*************************************************************************************************************************************************************/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct Cumle {
	string cumle;
	int cumHarfSayisi;
	int kelimeSayisi;
};
struct Kelime {
	string kelime;
	int kelimeHarfSayisi;
};

int cumleHarfSayisi(string str);
int cumleKelimeSayisi(Cumle);
void noktalamaIsaretleri(Cumle);
bool cumlePalindrommu(Cumle);
void kelimeHarfSayisi(Cumle);
void kelimeSesliHarfSayisi(Cumle);
void cumledePalindromKelimeVarmi(Cumle);

int main() {

	Cumle cum;

	cout << "Cumleyi giriniz:\n";
	getline(cin, cum.cumle);

	cum.cumHarfSayisi = cumleHarfSayisi(cum.cumle);
	cout << "'" << cum.cumle << "' cumlesindeki harf sayisi:" << cum.cumHarfSayisi - cumleKelimeSayisi(cum) + 1 << endl;

	cum.kelimeSayisi = cumleKelimeSayisi(cum);
	cout << "'" << cum.cumle << "' cumlesindeki kelime sayisi:" << cum.kelimeSayisi << endl;

	noktalamaIsaretleri(cum);

	kelimeHarfSayisi(cum);

	if (cumlePalindrommu(cum)) { cout << "Cumle palindrom\n"; } //c�mle polindrom ise "cumle polindrom" yaz�d�r�r.
	else { cout << "Cumle palindrom degil!\n"; }     //c�mle polindrom de�ilse "cimle polindrom de�ildir" yazd�r�r.

	kelimeSesliHarfSayisi(cum);
	cumledePalindromKelimeVarmi(cum);

	system("pause");
	return 0;
}

int cumleHarfSayisi(string cum) {
	int hs = cum.length();
	return hs;
}

int cumleKelimeSayisi(Cumle cum) {
	int  cumKSayi = 0;
	size_t i;

	if (isalpha(cum.cumle[0])) {     //c�mlede alfabetik karakter varsa sayac� artt�r.
		cumKSayi++;
	}

	for (i = 1; i < cum.cumle.length(); i++) {     //artan indis de�erine g�re c�mlenin uzunlu�u boyunca alfabetik karakter varsa saya� artar.
		if ((isalpha(cum.cumle[i])) && (!isalpha(cum.cumle[i - 1]))) {
			cumKSayi++;
		}
	}

	return cumKSayi;
}

void noktalamaIsaretleri(Cumle cum) {
	for (int i = 0; i < cum.cumle.length(); i++) {  //c�mle boyunca noktalama i�aretleri kontrol�n� sa�lan�yor
		switch (cum.cumle[i])
		{
		case '!':cout << "! ";
			break;
		case '?':cout << "? ";
			break;
		case ',':cout << ", ";
			break;
		case '.':cout << ".";
			break;
		case ';':cout << "; ";
			break;
		case ':':cout << ": ";
			break;
		case '\'':cout << "' ";
			break;
		default: break;
		}
	}
	cout << "\n";
}

bool cumlePalindrommu(Cumle cum) {

	if (cum.cumle.empty())  //c�mle girilmemi�se false de�eri d�ner.
		return false;

	int i = 0;                // birinci karakter
	int j = cum.cumle.length() - 1; // ikinci karakter

	while (i < j)
	{
		if (cum.cumle[i] != cum.cumle[j]) //e�it de�il ise false d�nd�r�r.
		{
			return false;
		}
		i++;
		j--;
	}
	return true;
}

vector<string> cumleKelimeleri(string str, string token)
{
	vector<string> cikis;
	size_t pos = string::npos; // size_t to avoid improbable overflow
	do
	{
		pos = str.find(token);
		cikis.push_back(str.substr(0, pos));
		if (string::npos != pos)
			str = str.substr(pos + token.size());
	} while (string::npos != pos);
	return cikis;
}

void kelimeHarfSayisi(Cumle cum) {

	Kelime kelimeler[20];
	vector<string> ke = cumleKelimeleri(cum.cumle, " ");
	for (int i = 0; i < ke.size(); i++) {  //kelime boyunca
		kelimeler[i].kelime = ke[i];
		kelimeler[i].kelimeHarfSayisi = cumleHarfSayisi(ke[i]);
		cout << kelimeler[i].kelime << ": " << kelimeler[i].kelimeHarfSayisi << endl;
	}
}
int sesliHarfSayici(string str) {
	int sayac = 0;
	for (int i = 0; i < str.length(); i++) { //artan indis de�erine g�re c�mle boyunca sesli harf varsa sayac� artt�r.
		if (str[i] == 'A' || str[i] == 'a' || str[i] == 'E' || str[i] == 'e' || str[i] == 'I' || str[i] == 'i' || str[i] == 'O' || str[i] == 'o' || str[i] == 'U' || str[i] == 'u') {
			sayac++;
		}
	} 
	return sayac;
}
void kelimeSesliHarfSayisi(Cumle cum) {

	Kelime kelimeler[20];
	vector<string> ke = cumleKelimeleri(cum.cumle, " ");
	for (int i = 0; i < ke.size(); i++) {
		kelimeler[i].kelime = ke[i];
		kelimeler[i].kelimeHarfSayisi = cumleHarfSayisi(ke[i]);
		cout << kelimeler[i].kelime << ": " << sesliHarfSayici(kelimeler[i].kelime) << endl;
	}
}

void cumledePalindromKelimeVarmi(Cumle cum) {

	Cumle c;
	vector<string> ke = cumleKelimeleri(cum.cumle, " ");
	for (int i = 0; i < ke.size(); i++) {
		c.cumle = ke[i];
		if (cumlePalindrommu(c)) {
			cout << c.cumle << " palindromdur!\n";
		}
		else { cout << c.cumle << " palindrom degildir!\n"; }
	}
}