#ifndef EXCEPTIONDEF
#define EXCEPTIONDEF

#include <string>
class Exception	{
	private:
		std::string mTag, mProblem;
	public:
        Exception();
		Exception(std::string tagString, std::string probString);
		void PrintDebug() const;
	    void SetmTag(std::string tagString);
        void SetmProblem(std::string problemString);
};

#endif //EXCEPTIONDEF
