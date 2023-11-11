#ifndef INTRA_ACCESSOR_CLASS_H
# define INTRA_ACCESSOR_CLASS_H

class	Accessor {
	
	public:
		Accessor( void );
		~Accessor( void );

		int		getFoo( void ) const;
		void	setFoo( int v );

	private:
		int	_foo;
};

#endif // !INTRA_ACCESSOR_CLASS_H
