/*
给定两个字符串，格式如下，"d:15,r:3#d:4"
#号分割线，输出第一个减去第二个的数量
*/

int main(void) {
	string s1("d:15,r:3#d:4");
	int h[128]{0};
	vector<char> mv;
	char last;
	int t = 0, i = 0;
	for (i = 0; i < s1.size(); ){
		if (isalpha(s1[i])){
			char ch = s1[i];
			mv.push_back(s1[i]);
			i += 2;
			t = 0;
			while (isdigit(s1[i])){
				t = t * 10 + s1[i] - '0';
				i++;
			}
			h[ch] = t;
		}
		
		if (s1[i] == '#')
			break;
		i++;
	}

	for (i = i+1; i < s1.size();){
		if (isalpha(s1[i])){
			
			char ch = s1[i];
			i += 2;
			t = 0;
			while (isdigit(s1[i])){
				t = t * 10 + s1[i] - '0';
				i++;
			}
			h[ch] -= t;
		}
		i++;
	}
	for (int j = 0; j < mv.size();j++){
		if (h[mv[j]] > 0){
			if (j > 0)
				cout << ',';
			cout << mv[j] << ':' << h[mv[j]];
		}

	}

	 
	return 0;
}

