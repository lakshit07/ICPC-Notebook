/*Trick #1: (A / B) % MOD = (A % (MOD * B)) / B

Conditions: none.
Advices: use this trick only if B can be not coprime with MOD, because new modulus = MOD * B can be large. How to avoid overflow working with large modulus read at the trick #5.
Trick #2: (A / B) % MOD = ((A % MOD) * (Bphi(MOD) - 1 % MOD)) % MOD
where phi is Euler's totient function

Conditions: B and MOD are coprimes.
Proof: (A / B) % MOD = ((A % MOD) * (B-1 % MOD)) % MOD from Exponentiation properties. And from Euler's theorem follows that Bphi(MOD) % MOD = 1. Let's multiply this equation by B-1 and we will get that B-1 % MOD = Bphi(MOD) - 1 % MOD.
Trick #3: (A / B) % MOD = ((A % MOD) * (BMOD - 2 % MOD)) % MOD

Conditions: B and MOD are coprimes, MOD is a prime number.
Advices: if you're sure that MOD is prime, better use this trick instead of trick #2. Remember that 109+7 and 109+9 are prime numbers.
Proof: if MOD is prime then phi(MOD) = MOD - 1 from properties of Euler's totient function. As it's just a particular case of trick #2, the rest of proof is similar.
Trick #4: power(A,N) % MOD = power(A,N % phi(MOD) )% MOD

Conditions: A and MOD are coprimes.
Advices: use this trick only if N can't be present in any standart data type, otherwise use Fast exponentiation.
Proof: from Euler's theorem follows that power(A,phi(MOD)) % MOD = 1. It's easy to see that power(A,X * phi(MOD)) % MOD = 1 too. So if N = X * phi(MOD) + Y then power(A,N) % MOD = power(A,Y) % MOD and minimal such Y = N % phi(MOD).
Trick #5: (A * B) % MOD
where MOD can't be present in int data type

function mulmod(A, B, MOD) {
    RES = 0;
    while (B > 0) {
        if (B is odd) {
            RES = (RES + A) % MOD;
        }
        A = (A * 2) % MOD;
        B = B / 2;
    }
    return RES;
}
Conditions: 2 * MOD can be present in a standart data type.
Advices: use this trick only if (A % MOD) * (B % MOD) can't be present in any standart data type because of overflow and you don't want to use BigIntegers. But keep in mind that it works in O(logB) operations, not in O(1) as (A % MOD) * (B % MOD).
Proof: if B is even then A * B = 2 * A * (B / 2), otherwise A * B = A + A * (B - 1).

Another way:-(to find (A*B) mod P where A*B exceeds range)
long long mulmod(long long a,long long b){long long q=(long long)(((long double)a*(long double)b)/(long double)P);long long r=a*b-q*P;if(r>P)r%=P;if(r<0)r+=P;return r;}*/
