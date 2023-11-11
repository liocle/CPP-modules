#ifndef INTRA_SAMPLE_2_CLASS_H
# define INTRA_SAMPLE_2_CLASS_H

class	Sample_2{
	public:
		char		a1;
		int			a2;
		float		a3;
		float const pi;
	Sample_2( char p1, int p2, float p3, float const pi);
	~Sample_2 (void );

	// the below const part means that the compiler will not allow any modification
	// of the current instance. In other words, it will not compile if trying to modify 
	// a value by assignation within the scope of this const member function: i.e.
	// this->pi = 2 , or this-> a1 = whatever etc... 

	void	member_function_const( void ) const;

};



#endif // !INTRA_SAMPLE_2_CLASS_H
