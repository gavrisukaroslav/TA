#include <iostream>
#include <iomanip>
#include <vector>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;
typedef long long ll;

// A. O(1) — без циклу
ll funcA(ll n, ll *sumOut = nullptr) {
    ll steps = 1;
    ll sum = n * (n + 1) / 2;
    if (sumOut) *sumOut = sum;
    return steps;
}

// L. O(log n) — цикл ділить навпіл
ll funcL(ll n) {
    ll steps = 0;
    ll j = n;
    while (j > 1) {
        steps++;
        j = j / 2;
    }
    return steps;
}

// B. O(n) — один цикл
ll funcB(ll n, ll *sumOut = nullptr) {
    ll steps = 0;
    ll sum = 0;
    for (ll i = 1; i <= n; i++) {
        steps++;
        sum += i;
    }
    if (sumOut) *sumOut = sum;
    return steps;
}

// D. O(n log n) — вкладений цикл, внутрішній ділить навпіл
ll funcD(ll n) {
    ll steps = 0;
    for (ll i = 1; i <= n; i++) {
        ll j = n;
        while (j > 1) {
            steps++;
            j = j / 2;
        }
    }
    return steps;
}

// C. O(n^2) — два вкладених цикли від 1 до n
ll funcC(ll n) {
    ll steps = 0;
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            steps++;
        }
    }
    return steps;
}

// E. O(2^n) — ітеративний експоненційний ріст
ll funcE(ll n) {
    ll steps = 0;
    ll limit = 1LL << n; // 2^n
    for (ll i = 0; i < limit; i++) {
        steps++;
    }
    return steps;
}

// F. O(n!) — факторіальний ріст
ll funcF(ll n) {
    ll steps = 0;
    ll limit = 1;
    for (ll i = 1; i <= n; i++) {
        limit *= i;
    }
    for (ll i = 0; i < limit; i++) {
        steps++;
    }
    return steps;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif
    vector<ll> nValues = {100, 200, 400, 800, 1600, 3200};
    vector<ll> nExp    = {8, 10, 12, 14, 16, 18};
    vector<ll> nFact   = {4, 5, 6, 7, 8, 9};

    cout << "=== Прогін A, L, B, D, C на n від 100 до 3200 ===\n";
    cout << left << setw(8) << "n" << " | " << setw(6) << "O(1)" << " | "
         << setw(10) << "O(log n)" << " | " << setw(8) << "O(n)" << " | "
         << setw(12) << "O(n log n)" << " | " << setw(12) << "O(n^2)" << "\n";
    cout << "------------------------------------------------------------------\n";

    for (ll n : nValues) {
        ll sumA, sumB;
        ll stepsA = funcA(n, &sumA);
        ll stepsL = funcL(n);
        ll stepsB = funcB(n, &sumB);
        ll stepsD = funcD(n);
        ll stepsC = funcC(n);

        cout << left << setw(8) << n << " | " << setw(6) << stepsA << " | "
             << setw(10) << stepsL << " | " << setw(8) << stepsB << " | "
             << setw(12) << stepsD << " | " << setw(12) << stepsC << "\n";

        if (sumA != sumB)
            cout << "  !!! Суми A і B не збігаються для n = " << n << "\n";
    }

    cout << "\n=== Прогін E та F на малих n ===\n";

    cout << "\n--- Функція E O(2^n) ---\n";
    cout << left << setw(4) << "n" << " | " << setw(12) << "Steps O(2^n)" << "\n";
    cout << "---------------------\n";
    for (ll n : nExp) {
        cout << left << setw(4) << n << " | " << setw(12) << funcE(n) << "\n";
    }

    cout << "\n--- Функція F O(n!) ---\n";
    cout << left << setw(4) << "n" << " | " << setw(12) << "Steps O(n!)" << "\n";
    cout << "--------------------\n";
    for (ll n : nFact) {
        cout << left << setw(4) << n << " | " << setw(12) << funcF(n) << "\n";
    }

    return 0;
}