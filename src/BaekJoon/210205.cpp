#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#define pii std::pair<std::string, int>

std::vector<pii> data;

int main() {

	std::string cut = ",,,,,,���鵿,��,����,,,,,,,,,,,,,,,������õ��,����,,,,,,";
	std::string str_buf;
	std::fstream fs;

	fs.open("���ֽ�.csv", std::ios::in);

	while (str_buf != cut)
	{
		std::getline(fs, str_buf);
	}

	std::getline(fs, str_buf);
	int total = 0;

	while (!fs.eof()) {

		std::string name, num, cnt;
		total++;
		for (int i = 0; i < 4; ++i) { getline(fs, str_buf, ','); }
		std::cout << str_buf << " "; name = str_buf;

		while (str_buf != "1����" && str_buf != "2����" && str_buf != "3����" &&str_buf != "4����")
		{
			if (fs.eof()) break;
			getline(fs, str_buf, ',');

		}

		std::cout << str_buf << " "; num = str_buf;

		for (int i = 0; i < 3; ++i) { getline(fs, str_buf, ','); }
		std::cout << str_buf << "\n"; cnt = str_buf;

		std::getline(fs, str_buf);

		bool find = false;
		if (cnt == "��" && num == "1����")
		{
			for (int i = 0; i < data.size(); ++i)
			{
				if (data[i].first == name) { data[i].second++; find = true; }
			}

			if (!find) { data.push_back(pii(name, 1)); }
		}
	}

	for (int i = 0; i < data.size(); ++i)
	{
		std::cout << data[i].first << " " << data[i].second << "\n";
	}

	std::cout << total;
	fs.close();
}
