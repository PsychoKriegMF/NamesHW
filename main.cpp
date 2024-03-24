#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <fstream>




int main() {
	setlocale(LC_ALL, "ru");

	std::queue<std::string> SecretSanta;
	std::vector<std::string> names; 

	std::ifstream file("Name.txt");
	if (!file.is_open())
	{
		std::cerr << "Error\n";
		return -1;
	}
	std::string name;
	while (file >> name) 
	{
		names.push_back(name); 
	}
	file.close();

	std::srand(static_cast<unsigned int>(std::time(nullptr))); 
	std::random_shuffle(names.begin(), names.end()); 

	for (const auto& name : names)
	{
		SecretSanta.push(name);
	}

	while (!SecretSanta.empty())
	{
		std::string Santa = SecretSanta.front();
		SecretSanta.pop();
		std::string Recipient = SecretSanta.front();
		SecretSanta.pop();
		std::cout << Santa << " -> " << Recipient << std::endl;
	}

	return 0;
}