#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// m-am "inspirat" cu functia de heapsort
// de pe acest site minunat https://www.programiz.com/dsa/heap-sort 
// Function to swap the the position of two elements
void swap(int* a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) 
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    // Swap and continue heapifying if root is not largest
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n) 
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);

        // Heapify root element to get highest element at root again
        heapify(arr, i, 0);
    }
}

void afisare(int v[100000], int n, int k)
{
    int i;//indicele vectorului
    int j;//variabila folosita pentru schimbarea elementelor de pe anumite pozitii
    j = 1;
    FILE* g;
    g = fopen("out.txt", "wt");//deschiderea fisierului in care afisam datele

    if (k == 1)//afisarea normala cand utilizatorul se gandeste ca nu gandesc cu 123421412412 pasi inainte
    {
        for (i = 0; i < n; i++)
            fprintf(g, "\n%d", v[i]);
    }
    else
    {
        for (i = 0; i < n; i++)//afisarea fiecarei subsecvente in fisier
        {
            if (i == ((k * j) - 1))//schimbarea variabilelor din vector astfel incat suma sa fie maxima
            {
                if (v[i] == v[n - j])
                {
                    swap(&v[i], &v[n - j + 1]);//in caz ca trebuie sa schimbe elementul cu unul deja schimbat(mai mic decat acesta) care este pe urmatoarea pozitie in vector
                }
                else
                {
                    swap(&v[i], &v[n - j]);
                }
                j++;
            }
            if (n % k == 0 && i == n - 1)//asigura ca nu afiseaza un numar de 2 ori
                break;

            fprintf(g, "%d ", v[i]);
            if (i == ((k * (j - 1)) - 1))
                fprintf(g, "\n");
        }
    }

    fclose(g);//inchiderea fisierului in care afisam datele
}

int main()
{
    int k;//numarul de subsecvente
    int n;//numarul de numere din sir
    int i;//indicele vectorului in care salvam sirul de numere
    int v[100000];//vectorul in care salvam sirul de numere

    //crearea fisierului
    FILE* f;
    f = fopen("in.txt", "rt");

    //citirea numarului de numere din sir si a numarului de subsecvente
    fscanf(f, "%d %d", &n, &k);

    //citirea elementelor vectorului din fisier
    i = 0;
    while (i < n)
    {
        fscanf(f, "%d", &v[i]);
        i++;
    }
    fclose(f);//inchiderea fisierului din care citim datele

    heapSort(v, n);//sortarea vectorului

    afisare(v, n, k);//afisarea in fisier

    return 0;
}