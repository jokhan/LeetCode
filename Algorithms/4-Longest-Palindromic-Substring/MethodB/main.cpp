/*
 * author: jokhan
 * date: 2016年 09月 08日 星期四 19:23:52 CST
 * function: main.cpp
 */
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
	public:
		string longestPalindrome( string s ) {
			//string result = "";
			int maxLength = 0;
			int left = 0, right = 0;
			int len = 0;
			for( int i = 0; i < s.length(); ++ i ) {
				int len1 = indicatorPldr( s, i, i );
				int len2 = indicatorPldr( s, i, i + 1 );
				len = max( len1, len2 );
				if( len > maxLength ) {
					maxLength = len;
					left = i - ( len - 1 ) / 2;
					right = i + len / 2;
				}
			}
			return s.substr( left, maxLength);
		}

	private:
		int indicatorPldr( string s, int left, int right ) {
			//以回文串的中心位置向两边扩散
			//找到最长回文串
			while( left >= 0 && right < s.length() ) {
				if( s.at( left ) != s.at( right ) ) {
					return right - left - 1;
				} else {
					-- left;
					++ right;
				}
			}
			return right - left - 1;
		}
};


int main()
{
	//string s = "ababc";
	string s = "kztakrekvefgchersuoiuatzlmwynzjhdqqftjcqmntoyckqfawikkdrnfgbwtdpbkymvwoumurjdzygyzsbmwzpcxcdmmpwzmeibligwiiqbecxwyxigikoewwrczkanwwqukszsbjukzumzladrvjefpegyicsgctdvldetuegxwihdtitqrdmygdrsweahfrepdcudvyvrggbkthztxwicyzazjyeztytwiyybqdsczozvtegodacdokczfmwqfmyuixbeeqluqcqwxpyrkpfcdosttzooykpvdykfxulttvvwnzftndvhsvpgrgdzsvfxdtzztdiswgwxzvbpsjlizlfrlgvlnwbjwbujafjaedivvgnbgwcdbzbdbprqrflfhahsvlcekeyqueyxjfetkxpapbeejoxwxlgepmxzowldsmqllpzeymakcshfzkvyykwljeltutdmrhxcbzizihzinywggzjctzasvefcxmhnusdvlderconvaisaetcdldeveeemhugipfzbhrwidcjpfrumshbdofchpgcsbkvaexfmenpsuodatxjavoszcitjewflejjmsuvyuyrkumednsfkbgvbqxfphfqeqozcnabmtedffvzwbgbzbfydiyaevoqtfmzxaujdydtjftapkpdhnbmrylcibzuqqynvnsihmyxdcrfftkuoymzoxpnashaderlosnkxbhamkkxfhwjsyehkmblhppbyspmcwuoguptliashefdklokjpggfiixozsrlwmeksmzdcvipgkwxwynzsvxnqtchgwwadqybkguscfyrbyxudzrxacoplmcqcsmkraimfwbauvytkxdnglwfuvehpxd";
	Solution slt;
	cout << slt.longestPalindrome( s ) << endl;
	return 0;
}
