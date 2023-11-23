class Date{

private:
	unsigned short day;
	unsigned short month;
	unsigned int year;

public:
	Date(){}

	Date(unsigned short day,
		 unsigned short month,
		 unsigned int year){

		this->day = day;
		this->month = month;
		this->year = year;
	}

	Date(Date* date){
		this->day = date->day;
		this->month = date->month;
		this->year = date->year;
	}

	void print(){
		std::cout << day << "/" << month << "/" << year;
	}
};