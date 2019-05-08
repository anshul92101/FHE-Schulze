
#include "functions.h" //check common functions for EQU(), ADD() and COM() functions in isequal2() , addMemo() and compare2()


long FindModulusChainLength(long numVal){
    long length;

    return length;
}

int main(){

    /*---------------READ SEND FILE ------------------*/

    long a ;
    long b ;
    long L ;

    cout<<"a "<<"b "<<"l "<<endl;
    cin>>a>>b>>L;
    
    cout << "Encrypted is beginning" << endl;
    long p = 2;
    long r = 1;
    long d = 1;
    long c = 2;
    long k = 128;
    long w = 64;
    long num = 10;
    long s = 16;
    long m = 255; 
   
    FHEcontext context(m,p,r);
    long n = pow(p,r);



    long iter,iter1;

    AddPrimesBySize(context,5,false);
    buildModChain(context,L,c);
    FHESecKey secretKey(context);
    const FHEPubKey& publicKey = secretKey;
    secretKey.GenSecKey(w);
    addSome1DMatrices(secretKey);

    ZZX GZZX = context.alMod.getFactorsOverZZ()[0];
    EncryptedArray ea(context,GZZX);

    long nslots = ea.size();
    cout<<"nslots are "<<nslots<<endl;
    cout << "DONE Configuration" << endl;

    fstream sendFile("pubkey",fstream::out|fstream::trunc);
    assert(sendFile.is_open());

    sendFile << publicKey << endl;

    fstream secretFile("secretkey",fstream::out|fstream::trunc);
    assert(secretFile.is_open());

    // Output ScretKey 
    secretFile << secretKey << endl;

    secretFile.close();


    // Output Ciphertext
 
    sendFile.close();
    
    long res=0;
    long res1, res2;
    vector<long> vVal;

    vector<long> zeroOne (nslots,0);
    Ctxt cZeroOne (publicKey);
    zeroOne[0] = 1;
    ea.encrypt(cZeroOne,publicKey,zeroOne);
    
    vector<long> oneZero(nslots,0);
    oneZero[nslots - 1] = 1;
    Ctxt cOneZero (publicKey);
    ea.encrypt(cOneZero,publicKey,oneZero);

    vector<long> vOne (nslots,1);
    Ctxt cOne(publicKey);
    ea.encrypt(cOne,publicKey,vOne);


    Ctxt aC(publicKey);
    ea.encrypt(aC,publicKey,convertToCoeArray(a,nslots));

    Ctxt bC(publicKey);
    ea.encrypt(bC,publicKey,convertToCoeArray(b,nslots));


    Ctxt cSum = addMemo(aC,bC,ea,nslots);





   ea.decrypt(cSum,secretKey,vVal);
    res = convertToL(vVal,nslots);
    cout<<res<<endl;
  
/*
    ea.decrypt(aC,secretKey,vVal);
    res1 = convertToL(vVal,nslots);

    ea.decrypt(bC,secretKey,vVal);
    res2 = convertToL(vVal,nslots);

    cout<<res1<<" ";
    cout<<res2<<endl;


    clock_t tStart = clock();

    Ctxt cEq = isEqual2(aC,bC,cOne,ea,nslots);

    printf("Time taken for Equality: %.2fs\n",(double)(clock() - tStart)/CLOCKS_PER_SEC); 

    ea.decrypt(cEq,secretKey,vVal);
    res = convertToL(vVal,nslots);

    cout<<"Equality "<<res<<endl;

    clock_t tStart = clock();

    Ctxt cmp = compare2(aC,bC,ea,cZeroOne,cOneZero,cOne,nslots);

    printf("Time taken for binary addition: %.2fs\n",(double)(clock() - tStart)/CLOCKS_PER_SEC); 

    ea.decrypt(cmp,secretKey,vVal);


    res = convertToL(vVal,nslots);
    cout<<"Cmp "<<res<<endl;

*/

    return 0;

    /*------------- SORTING PROCESS -----------------*/



    

    /*----------------- OUPUT result.txt ---------------------------------*
    fstream sendFile("result.txt",fstream::out|fstream::trunc);
    sendFile << numVal << endl;
    for(iter = 0 ; iter < numVal ; iter++){
        sendFile << resultCipher[iter] << endl; 
        if(resultCipher[iter].findBaseLevel() < lowestdepth){
            lowestdepth = resultCipher[iter].findBaseLevel();
        }
    }
    sendFile.close();

    clock_t tStart = clock();

    printf("Time taken : %.2fs\n",(double)(clock() - tStart)/CLOCKS_PER_SEC); */
    
}







