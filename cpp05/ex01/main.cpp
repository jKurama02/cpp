#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
	Bureaucrat Gino("Gino", 66);
	Form ForumPolonia("ForumPolonia", 0, 40, 20);
	try{
	Form ForumItalia("ForumItalia", 0, 40, 20);}
	catch(std::exception &str)
	{
		std::cout << "Exception caught: " << str.what() << std::endl;
	}
	Gino.signForm(ForumPolonia);
	Gino.decrement();
	Gino.increment();
	std::cout << Gino ;
	return 0;
}
