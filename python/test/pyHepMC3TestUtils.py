import re
def COMPARE_ASCII_FILES(f1,f2):
 file1=open(f1)
 file2=open(f2)
 print ("Run comparison")
 string1=" "
 string2=" "
 j=0
 while string1 and string2:
     j=j+1
     string1=file1.readline()
     string2=file2.readline()
     if (string1 != string2):
            print (j,"-th strings are not equal", "\n")
            print ("   ", string1 ,"\n")
            print ("   ", string2 ,"\n")
            if not re.match(r'HepMC::Version',string1):
             file1.close()
             file2.close()
             return 1
 file1.close()
 file2.close()
 return 0