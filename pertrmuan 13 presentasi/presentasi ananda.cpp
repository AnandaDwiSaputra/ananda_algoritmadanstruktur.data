#include <iostream>
#include <climits>
using namespace std;

const int MAX = 20;
const int INF = INT_MAX;

string siswa[MAX] = {
    "Kyanka", "Dava", "Doni", "Wildan", "Haikal",
    "Agus", "Rofii", "Jonathan", "Annisa", "Azizah",
    "Abrar", "Steven", "Yunita", "Nanda", "Ale",
    "Agung", "Martin", "Sudrajat"};
int jumlahSiswa = 18;
int graph[MAX][MAX];

int cariIndex(string nama)
{
    for (int i = 0; i < jumlahSiswa; i++)
        if (siswa[i] == nama)
            return i;
    return -1;
}

void tambahJalur(string a, string b, int w)
{
    int i = cariIndex(a);
    int j = cariIndex(b);
    if (i != -1 && j != -1)
    {
        graph[i][j] = w;
        graph[j][i] = w;
    }
}

void buatGraf()
{
    for (int i = 0; i < jumlahSiswa; i++)
        for (int j = 0; j < jumlahSiswa; j++)
            graph[i][j] = (i == j ? 0 : INF);

    tambahJalur("Kyanka", "Dava", 1);
    tambahJalur("Dava", "Doni", 1);
    tambahJalur("Doni", "Wildan", 2);
    tambahJalur("Wildan", "Haikal", 4);
    tambahJalur("Haikal", "Agus", 4);
    tambahJalur("Agus", "Rofii", 2);
    tambahJalur("Rofii", "Jonathan", 2);
    tambahJalur("Jonathan", "Annisa", 1);
    tambahJalur("Annisa", "Doni", 4);
    tambahJalur("Annisa", "Azizah", 2);
    tambahJalur("Azizah", "Dava", 2);
    tambahJalur("Azizah", "Abrar", 1);
    tambahJalur("Abrar", "Steven", 2);
    tambahJalur("Steven", "Azizah", 1);
    tambahJalur("Martin", "Sudrajat", 3);
    tambahJalur("Sudrajat", "Nanda", 4);
    tambahJalur("Nanda", "Yunita", 2);
    tambahJalur("Yunita", "Annisa", 2);
    tambahJalur("Martin", "Nanda", 1);
    tambahJalur("Jonathan", "Wildan", 1);
    tambahJalur("Nanda", "Ale", 2);
    tambahJalur("Ale", "Rofii", 2);
    tambahJalur("Ale", "Agung", 1);
    tambahJalur("Rofii", "Agus", 2);
}

void dijkstra(int asal, int jarak[], int prev[])
{
    bool visited[MAX];
    for (int i = 0; i < jumlahSiswa; i++)
    {
        jarak[i] = INF;
        visited[i] = false;
        prev[i] = -1;
    }

    jarak[asal] = 0;

    for (int i = 0; i < jumlahSiswa; i++)
    {
        int u = -1;
        for (int j = 0; j < jumlahSiswa; j++)
        {
            if (!visited[j] && (u == -1 || jarak[j] < jarak[u]))
                u = j;
        }

        if (u == -1)
            break;
        visited[u] = true;

        for (int v = 0; v < jumlahSiswa; v++)
        {
            if (graph[u][v] != INF && jarak[v] > jarak[u] + graph[u][v])
            {
                jarak[v] = jarak[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }
}

void cetakJalurKeTujuan(int asal, int jarak[], int prev[], string tujuanNama)
{
    int tujuan = cariIndex(tujuanNama);
    if (tujuan == -1)
    {
        cout << "Siswa tujuan tidak ditemukan.\n";
        return;
    }

    cout << "\nFITUR 1: Jalur tercepat dari Martin ke " << tujuanNama << ":\n";
    if (jarak[tujuan] == INF)
    {
        cout << "Tidak ada jalur yang tersedia.\n";
        return;
    }

    cout << "Jarak = " << jarak[tujuan] << ", Jalur: ";
    int path[MAX], len = 0;
    for (int at = tujuan; at != -1; at = prev[at])
        path[len++] = at;
    for (int i = len - 1; i >= 0; i--)
    {
        cout << siswa[path[i]];
        if (i != 0)
            cout << " -> ";
    }
    cout << endl;
}

void floydWarshallDari(int asal)
{
    int dist[MAX][MAX];
    for (int i = 0; i < jumlahSiswa; i++)
        for (int j = 0; j < jumlahSiswa; j++)
            dist[i][j] = graph[i][j];

    for (int k = 0; k < jumlahSiswa; k++)
        for (int i = 0; i < jumlahSiswa; i++)
            for (int j = 0; j < jumlahSiswa; j++)
                if (dist[i][k] != INF && dist[k][j] != INF)
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

    cout << "\nFITUR 2: Matriks Jarak Terpendek dari Martin (Floyd-Warshall)\n";
    cout << "Siswa Tujuan\tJarak dari Martin\n";
    cout << "--------------\t------------------\n";
    for (int j = 0; j < jumlahSiswa; j++)
    {
        if (j == asal)
            continue;
        cout << siswa[j] << "\t\t";
        if (dist[asal][j] == INF)
            cout << "Tidak ada jalur yang tersedia\n";
        else
            cout << dist[asal][j] << endl;
    }
}

int main()
{
    buatGraf();
    int asal = cariIndex("Martin"); 
    int jarak[MAX], prev[MAX];

    dijkstra(asal, jarak, prev);

    string tujuan;
    cout << "FITUR 1: Jalur Tercepat\n";
    cout << "Masukkan siswa tujuan: ";
    cin >> tujuan;
    cetakJalurKeTujuan(asal, jarak, prev, tujuan);

    char cetak;
    cout << "\nFITUR 2: Cetak Matriks Jarak Terpendek (Y/T)? ";
    cin >> cetak;
    if (cetak == 'Y' || cetak == 'y')
    {
        floydWarshallDari(asal);
    }

    return 0;
}
