//
// Created by stud-05 on 10/19/24.
//
#ifndef MATRIXLIB_HPP
#define MATRIXLIB_HPP

template<typename T>
void SquareMatrix<T>::setMatrix(const vector<vector<T> >& m)
{
    matrix = m;
    size = m.size();
}
template<typename T>
void SquareMatrix<T>::transpose_rows(const int row1, const int row2) {
    for(int column = 0; column < size; column++) {
        swap(matrix[row1][column], matrix[row2][column]);
    }
}
template<typename T>
void SquareMatrix<T>::multiply_row(const int row, const T val) {
    for(int column = 0; column < size; column++)matrix[row][column] *= val;
}
template<typename T>
void SquareMatrix<T>::add_to_row(const int row_to, const int row_from, const T val) {
    for(int column = 0; column < size; column++) {
        matrix[row_to][column] += matrix[row_from][column] * val;
    }
}
template <typename T>
void SquareMatrix<T>::make_identity()
{
    for(int row = 0; row < size; row++)
    {
        for(int column = 0; column < size; column++)
        {
            if(row == column)matrix[row][column] = 1;
            else matrix[row][column] = 0;
        }
    }
}
template <typename T>
vector<vector<T>> SquareMatrix<T>::get_matrix()
{
    return matrix;
}

template<typename T>
SquareMatrix<T> SquareMatrix<T>::reverse(){
    if(size == 0)throw std::invalid_argument("SquareMatrix is empty");
    SquareMatrix<T>Copy(*this);
    SquareMatrix<T> Res(size);
    Res.make_identity();

    for(int row = 0; row < size; row++) { // direct Gauss
        if(Copy.matrix[row][row] == 0) {
            for(int i = row + 1; i < size; i++)
                if(Copy.matrix[i][row] != 0) {
                    Res.transpose_rows(row, i);
                    Copy.transpose_rows(row, i);
                    break;
                }

            if(Copy.matrix[row][row] == 0)throw std::invalid_argument("Determinant is zero");
        }
        Res.multiply_row(row, 1.0 / Copy.matrix[row][row]);
        Copy.multiply_row(row, 1.0 / Copy.matrix[row][row]);
        for(int i = row + 1; i < size; i++) {
            Res.add_to_row(i, row, -Copy.matrix[i][row]);
            Copy.add_to_row(i, row, -Copy.matrix[i][row]);
        }

    }

    for(int row = size - 1; row > 0; --row) { // reverse Gauss
        for(int i = row - 1; i >= 0; --i) {
            Res.add_to_row(i, row, -Copy.matrix[i][row]);
            Copy.add_to_row(i, row, -Copy.matrix[i][row]);
        }
    }
    return Res;
}

template<typename T>
void SquareMatrix<T>::show()
{
    for(int row = 0; row < size; row++)
    {
        for(int column = 0; column < size; column++)
        {
            cout << matrix[row][column] << " ";
        }
        cout << "\n";
    }
}

template <typename T>
SquareMatrix<T>& SquareMatrix<T>::operator=(SquareMatrix<T> const& other)
{
    size = other.size;
    matrix = vector<vector<T>>(other.matrix);
    return *this;
}

template <typename T>
SquareMatrix<T> SquareMatrix<T>::operator*(SquareMatrix<T> const& other)
{
    if(size != other.size)throw std::invalid_argument("Matrices have different dimensions");
    SquareMatrix<T> product(size);
    for(int row = 0; row < size; row++)
    {
        for(int column = 0; column < size; column++)
        {
            for(int i = 0; i < size; i++)
            {
                product.matrix[row][column] += matrix[row][i] * other.matrix[i][column];
            }
        }
    }
    return product;
}

template <typename T>
bool SquareMatrix<T>::operator==(SquareMatrix<T> const& other)
{
    if(size != other.size)return false;
    for(int row = 0; row < size; row++)
    {
        for(int column = 0; column < size; column++)
        {
            if(matrix[row][column] != other.matrix[row][column])return false;
        }
    }
    return true;
}

#endif //MATRIXLIB_HPP