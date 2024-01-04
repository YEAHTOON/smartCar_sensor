#include "Matrix.h"

/*
 * 社会叶
 */

//初始化矩阵
matrix matrix_init(int row,int col)
{
    matrix result;

    result.element = (float**)malloc(row * sizeof(float*));
    for(int i = 0; i < col; i++)
    {
        result.element[i] = (float*)malloc(col * sizeof(float));
    }
    result.row = row;
    result.col = col;

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            result.element[i][j] = 0.0f;
        }
    }

    return result;
}

//矩阵相加
matrix matrix_plus(matrix left_matrix,matrix right_matrix)
{
    matrix result;
    result = matrix_init(left_matrix.row,left_matrix.col);

    for(int i = 0; i < left_matrix.row; i++)
    {
        for(int j = 0; j < left_matrix.col; j++)
        {
            result.element[i][j] = left_matrix.element[i][j] + right_matrix.element[i][j];
        }
    }

    return result;
}

//矩阵相乘
matrix matrix_multiply(matrix left_matrix,matrix right_matrix)
{
    float inner_product; //内积
    matrix result;
    result = matrix_init(left_matrix.row,right_matrix.col);

    for(int i = 0; i < left_matrix.row; i++)
    {
        for(int j = 0; j < right_matrix.col; j++)
        {
            inner_product = 0.0f;//内积置零

            for(int k = 0; k < left_matrix.col; k++) //求内积
            {
                inner_product += left_matrix.element[i][k] * right_matrix.element[k][j];
            }

            result.element[i][j] = inner_product;
        }
    }

    return result;
}

//矩阵转置
matrix matrix_transposition(matrix input_matrix)
{
    matrix result;
    result = matrix_init(input_matrix.col,input_matrix.row);

    for(int i = 0; i < input_matrix.row; i++)
    {
        for(int j = 0; j < input_matrix.row; j++)
        {
            result.element[i][j] = input_matrix.element[j][i];
        }
    }

    return result;
}

//矩阵求逆
matrix Gaussian_elimination(matrix input_martrix)
{
    int i, j, k;
    float W[input_martrix.row][2*input_martrix.row];
    float tem_1, tem_2, tem_3;

    matrix result;
    result = matrix_init(input_martrix.row,input_martrix.row);

    // 对矩阵右半部分进行扩增
    for(i = 0;i < input_martrix.row; i++)
    {
        for(j = 0;j < 2 * input_martrix.row; j++)
        {
            if(j<input_martrix.row)
            {
                W[i][j] = (float) input_martrix.element[i][j];
            }
            else
            {
                W[i][j] = (float) (j-input_martrix.row == i ? 1:0);
            }
        }
    }

    for(i=0;i<input_martrix.row;i++)
    {
        // 判断矩阵第一行第一列的元素是否为0，若为0，继续判断第二行第一列元素，直到不为0，将其加到第一行
        if( ((int) W[i][i]) == 0)
        {
            for(j=i+1;j<input_martrix.row;j++)
            {
                if( ((int) W[j][i]) != 0 ) break;
            }
            if(j == input_martrix.row)
            {
                break;
            }
            //将前面为0的行加上后面某一行
            for(k=0;k<2*input_martrix.row;k++)
            {
                W[i][k] += W[j][k];
            }
        }

        //将前面行首位元素置1
        tem_1 = W[i][i];
        for(j=0;j<2*input_martrix.row;j++)
        {
            W[i][j] = W[i][j] / tem_1;
        }

        //将后面所有行首位元素置为0
        for(j=i+1;j<input_martrix.row;j++)
        {
            tem_2 = W[j][i];
            for(k=i;k<2*input_martrix.row;k++)
            {
                W[j][k] = W[j][k] - tem_2 * W[i][k];
            }
        }
    }

    // 将矩阵前半部分标准化
    for(i=input_martrix.row-1;i>=0;i--)
    {
        for(j=i-1;j>=0;j--)
        {
            tem_3 = W[j][i];
            for(k=i;k<2*input_martrix.row;k++)
            {
                W[j][k] = W[j][k] - tem_3*W[i][k];
            }
        }
    }

    //得出逆矩阵
    for(i=0;i<input_martrix.row;i++)
    {
        for(j=input_martrix.row;j<2*input_martrix.row;j++)
        {
            result.element[i][j-input_martrix.row] = W[i][j];
        }
    }

    return result;
}

//释放储存空间
void matrix_free(matrix m)
{
    for(int i = 0; i < m.row; i++)
    {
        free(m.element[i]);
    }
    free(m.element);
}
