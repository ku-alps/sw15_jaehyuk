#include <iostream>
#include <vector>
using namespace std;

pair<int, int> arr[21][21];
pair<int, int> board[21][21];
int n;

void oper(int num)
{
  if (num == 0)
  { //up
    for (int col = 0; col < n; col++)
    {
      vector<pair<int, int> > temp_vec;
      for (int row = 0; row < n; row++)
      {
        if (board[row][col].second == 0 || board[row][col].first == 0)
        {
          continue;
        }
        pair<int, int> temp = board[row][col];
        row++;
        int flag = 0;
        while (row < n)
        {
          if (board[row][col].first != 0)
          {
            if (temp.second == board[row][col].second)
            {
              temp_vec.push_back(make_pair(temp.first + board[row][col].first, temp.second + 1));
              flag = 1;
              break;
            }
            else
            {
              temp_vec.push_back(temp);
              row--;
              flag = 1;
              break;
            }
          }
          row++;
        }
        if (flag == 0)
        {
          temp_vec.push_back(temp);
        }
      }
      for (int i = 0; i < n; i++)
      {
        if (i < temp_vec.size())
        {
          arr[i][col].first = temp_vec[i].first;
          arr[i][col].second = temp_vec[i].second;
        }
        else
        {
          arr[i][col] = make_pair(0, 0);
        }
      }
    }
  }
  else if (num == 1)
  { //right
    for (int row = 0; row < n; row++)
    {
      vector<pair<int, int> > temp_vec;
      for (int col = n - 1; col >= 0; col--)
      {
        if (board[row][col].second == 0 || board[row][col].first == 0)
        {
          continue;
        }
        pair<int, int> temp = board[row][col];
        col--;
        int flag = 0;
        while (col >= 0)
        {
          if (board[row][col].first != 0)
          {
            if (temp.second == board[row][col].second)
            {
              temp_vec.push_back(make_pair(temp.first + board[row][col].first, temp.second + 1));
              flag = 1;
              break;
            }
            else
            {
              temp_vec.push_back(temp);
              col++;
              flag = 1;
              break;
            }
          }
          col--;
        }
        if (flag == 0)
        {
          temp_vec.push_back(temp);
        }
      }
      int k = 0;
      for (int i = n - 1; i >= 0; i--)
      {
        if (k < temp_vec.size())
        {
          arr[row][i].first = temp_vec[k].first;
          arr[row][i].second = temp_vec[k].second;
        }
        else
        {
          arr[row][i] = make_pair(0, 0);
        }
        k++;
      }
    }
  }
  else if (num == 2)
  { //down
    for (int col = 0; col < n; col++)
    {
      vector<pair<int, int> > temp_vec;
      for (int row = n - 1; row >= 0; row--)
      {
        if (board[row][col].second == 0 || board[row][col].first == 0)
        {
          continue;
        }
        pair<int, int> temp = board[row][col];
        row--;
        int flag = 0;
        while (row >= 0)
        {
          if (board[row][col].first != 0)
          {
            if (temp.second == board[row][col].second)
            {
              temp_vec.push_back(make_pair(temp.first + board[row][col].first, temp.second + 1));
              flag = 1;
              break;
            }
            else
            {
              temp_vec.push_back(temp);
              row++;
              flag = 1;
              break;
            }
          }
          row--;
        }
        if (flag == 0)
        {
          temp_vec.push_back(temp);
        }
      }
      int k = 0;
      for (int i = n - 1; i >= 0; i--)
      {
        if (k < temp_vec.size())
        {
          arr[i][col].first = temp_vec[k].second;
          arr[i][col].second = temp_vec[k].second;
        }
        else
        {
          arr[i][col] = make_pair(0, 0);
        }
        k++;
      }
    }
  }
  else if (num == 3)
  { //left
    for (int row = 0; row < n; row++)
    {
      vector<pair<int, int> > temp_vec;
      for (int col = 0; col < n; col++)
      {
        if (board[row][col].second == 0 || board[row][col].first == 0)
        {
          continue;
        }
        pair<int, int> temp = board[row][col];
        col++;
        int flag = 0;
        while (col < n)
        {
          if (board[row][col].first != 0)
          {
            if (temp.second == board[row][col].second)
            {
              temp_vec.push_back(make_pair(temp.first + board[row][col].first, temp.second + 1));
              flag = 1;
              break;
            }
            else
            {
              temp_vec.push_back(temp);
              col--;
              flag = 1;
              break;
            }
          }
          col++;
        }
        if (flag == 0)
        {
          temp_vec.push_back(temp);
        }
      }
      for (int i = 0; i < n; i++)
      {
        if (i < temp_vec.size())
        {
          arr[row][i].first = temp_vec[i].first;
          arr[row][i].second = temp_vec[i].second;
        }
        else
        {
          arr[row][i] = make_pair(0, 0);
        }
      }
    }
  }
}

int main()
{
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> board[i][j].first;
      if (board[i][j].first != 0)
      {
        board[i][j].second = 1;
      }
      else if (board[i][j].first == 0)
      {
        board[i][j].second = 0;
      }
    }
  }
  int sum = 0;
  int cnt = 0;
  int mmax = -1;
  for (int a = 0; a < 4; a++)
  {
    for (int b = 0; b < 4; b++)
    {
      for (int c = 0; c < 4; c++)
      {
        for (int d = 0; d < 4; d++)
        {
          for (int e = 0; e < 4; e++)
          {

            for (int i = 0; i < n; i++)
            {
              for (int j = 0; j < n; j++)
              {
                arr[i][j].first = board[i][j].first;
                arr[i][j].second = board[i][j].second;
              }
            }
            //arr = oper(0,arr);

            oper(a);
            oper(b);
            oper(c);
            oper(d);
            oper(e);

            for (int i = 0; i < n; i++)
            {
              for (int j = 0; j < n; j++)
              {
                mmax = max(mmax, arr[i][j].first);
              }
            }
          }
        }
      }
    }
  }
  cout << mmax << '\n';
}