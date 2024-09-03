#include <iostream>

class Matrix; // forward declarattion of class

class Vector
{
	int *vector;
	int sizeOfVector;

public:
	Vector(int size = 0) : sizeOfVector(size)
	{
		vector = new int(size);
	}

	~Vector(void)
	{
		if (vector)
			delete vector;
		vector = NULL;
	}
	void accept(void)
	{
		std::cout << "Accepting Vector\n\n";

		for (int i = 0; i < sizeOfVector; i++)
		{
			std::cout << "Enter element of vector v[" << i << "]: ";
			std::cin >> vector[i];
		}
		std::cout << std::endl << std::endl;
	}

	void display(void)
	{
		std::cout << "Displaying Vector \n\n";
		for (int i = 0; i < sizeOfVector; i++)
		{
			std::cout << vector[i] << " ";
		}
		std::cout << std::endl << std::endl;
	}

	void clear(void)
	{
		for (int i = 0; i < sizeOfVector; i++)
		{
			vector[i] = 0;
		}
	}
	friend Vector product(Matrix *, Vector *);
};

class Matrix
{
	int **matrix;
	int row;
	int column;

public:
	Matrix(int row = 0, int column = 0) : row(row), column(column)
	{
		matrix = new int*[row];

		for (int i = 0; i < column; i++)
		{
			matrix[i] = new int[column];
		}
	}

	~Matrix(void)
	{
		for (int i = 0; i < column; i++)
		{
			if (matrix[i])
				delete []matrix[i];
		}

		if (matrix)
			delete []matrix;
	}

	void accept(void)
	{
		std::cout << "Accepting Matrix : \n\n";

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				std::cout << "Enter Matrix[" << i << "][" << j << "] : ";
				std::cin >> matrix[i][j];
			}
		}
	}

	void display(void)
	{
		std::cout << "Displaying Matrix \n\n";
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{
				std::cout << matrix[i][j] << " ";
				
			}
			std::cout << std::endl;
		}
	}
	friend Vector product(Matrix *, Vector *);
};

Vector product(Matrix *, Vector *);

int main(void)
{
	int vectorSize = 0;
	std::cout << "Enter Size Of Vector : ";
	std::cin >> vectorSize;
	
	Vector vector(vectorSize);
	vector.accept();
	
	int row = 0;
	int column = 0;

	std::cout << "Enter Number Of Rows : ";
	std::cin >> row;
	std::cout << "Enter Number Of Columns : ";
	std::cin >> column;

	Matrix matrix(row, column);
	
	matrix.accept();

	Vector result = product(&matrix, &vector);
	
	vector.display();
	matrix.display();
	result.display();
	
	return(0);
}

Vector product(Matrix *matrix, Vector *vector)
{
	if (matrix->column != vector->sizeOfVector)
	{
		std::cout << "PLEASE ENTER VALID MATRIX FOR MATRIX MULTIPLICATION (NUMBER OF COLUMN OF MATRIX IS EQAUL TO NUMBER OF ROWS IN VECTOR) !!!\n\n";
		exit(EXIT_FAILURE);
	}

	Vector resultVector(matrix->row);
	resultVector.clear();

	for (int i = 0; i < matrix->row; i++)
	{
		for (int j = 0; j < vector->sizeOfVector; j++)
		{
			resultVector.vector[i] = resultVector.vector[i] + matrix->matrix[i][j] * vector->vector[j];
		}
	}

	return(resultVector);
}
