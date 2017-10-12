/*----------------------------------------------------------------
Copyright (c) 2015 Author: Jagadeesh Vasudevamurthy
file: ../str/str.cpp ulongnum.cpp ulongnumtest.cpp

On linux:
g++  ../str/str.cpp  ulongnum.cpp ulongnumtest.cpp
valgrind a.out
valgrind --leak-check=full -v a.out
-- All heap blocks were freed -- no leaks are possible

-----------------------------------------------------------------*/

/*----------------------------------------------------------------
This file test ulongnum object
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
All includes here
-----------------------------------------------------------------*/
#include "ulongnum.h"
#include "vld.h"

/*--------------------------------------------------------
local to this file. Change verbose = true for debugging
----------------------------------------------------------*/
static bool verbose = true;

/*----------------------------------------------------------------
CANNOT CHANGE ANYTHING IN THIS FILE
-----------------------------------------------------------------*/

/*----------------------------------------------------------------
test multiplication
-----------------------------------------------------------------*/

static void test_multiplication() {
	ulongnum a(789, verbose);
	cout << "a = " << a << endl;
	ulongnum b("56", verbose);
	cout << "b = " << b << endl;
	ulongnum ans = a * b;
	cout << "ans = " << ans << endl;
	assert(ans == 44184);

	ulongnum rsa129("114381625757888867669235779976146612010218296721242362562561842935706935245733897830597123563958705058989075147599290026879543541", verbose);
	ulongnum p1("3490529510847650949147849619903898133417764638493387843990820577", verbose);
	ulongnum p2("32769132993266709549961988190834461413177642967992942539798288533", verbose);
	ulongnum p1p2 = p1 * p2;
	cout << "p1 = " << p1 << endl;
	cout << "p2 = " << p2 << endl;
	cout << "p1p2 = " << p1p2 << endl;
	assert(p1p2 == rsa129);
}
#if 0
/*----------------------------------------------------------------
test addition
-----------------------------------------------------------------*/
static void test_addition() {
	ulongnum a(9789, verbose);
	ulongnum b("100000", verbose);
	ulongnum c('7', verbose);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
	ulongnum sum = a + 78 + b + c;
	cout << "sum = a + 78 + b + c = " << sum << endl;
	assert(sum == 109874);
}

/*----------------------------------------------------------------
test basic
-----------------------------------------------------------------*/
static void test_basic() {
	ulongnum a(789, verbose);
	cout << "a = " << a << endl;
	ulongnum b("56789", verbose);
	cout << "b = " << b << endl;
	ulongnum c("123456789012345678901234567890123456789012345678901234567890", verbose);
	cout << "c = " << c << endl;
	ulongnum ta(a);
	cout << "ta = " << ta << endl;
	ta = b;
	cout << "ta = " << ta << endl;
}
/*----------------------------------------------------------------
test factorial
-----------------------------------------------------------------*/
static void test_factorial() {
	// http://puzzles.nigelcoldwell.co.uk/nineteen.htm
	{
		const char* fact100 = "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000";
		clock_t start = clock();
		ulongnum c100;
		c100.set_display(verbose);
		c100.factorial(100);
		cout << "Factorial of 100 = " << endl;
		cout << c100 << endl;
		assert(c100 == fact100);
		clock_t end = clock();
		double d = double(end - start) / CLOCKS_PER_SEC;
		cout << "Run time for !100 = " << " is " << d << " secs" << endl;
	}

	//http://justinwhite.com/big-calc/1000.html
	{
		const char* fact1000 = "402387260077093773543702433923003985719374864210714632543799910429938512398629020592044208486969404800479988610197196058631666872994808558901323829669944590997424504087073759918823627727188732519779505950995276120874975462497043601418278094646496291056393887437886487337119181045825783647849977012476632889835955735432513185323958463075557409114262417474349347553428646576611667797396668820291207379143853719588249808126867838374559731746136085379534524221586593201928090878297308431392844403281231558611036976801357304216168747609675871348312025478589320767169132448426236131412508780208000261683151027341827977704784635868170164365024153691398281264810213092761244896359928705114964975419909342221566832572080821333186116811553615836546984046708975602900950537616475847728421889679646244945160765353408198901385442487984959953319101723355556602139450399736280750137837615307127761926849034352625200015888535147331611702103968175921510907788019393178114194545257223865541461062892187960223838971476088506276862967146674697562911234082439208160153780889893964518263243671616762179168909779911903754031274622289988005195444414282012187361745992642956581746628302955570299024324153181617210465832036786906117260158783520751516284225540265170483304226143974286933061690897968482590125458327168226458066526769958652682272807075781391858178889652208164348344825993266043367660176999612831860788386150279465955131156552036093988180612138558600301435694527224206344631797460594682573103790084024432438465657245014402821885252470935190620929023136493273497565513958720559654228749774011413346962715422845862377387538230483865688976461927383814900140767310446640259899490222221765904339901886018566526485061799702356193897017860040811889729918311021171229845901641921068884387121855646124960798722908519296819372388642614839657382291123125024186649353143970137428531926649875337218940694281434118520158014123344828015051399694290153483077644569099073152433278288269864602789864321139083506217095002597389863554277196742822248757586765752344220207573630569498825087968928162753848863396909959826280956121450994871701244516461260379029309120889086942028510640182154399457156805941872748998094254742173582401063677404595741785160829230135358081840096996372524230560855903700624271243416909004153690105933983835777939410970027753472000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
		clock_t start = clock();
		ulongnum c1000;
		c1000.set_display(verbose);
		c1000.factorial(1000);
		cout << "Factorial of 1000 = " << endl;
		cout << c1000 << endl;
		assert(c1000 == fact1000);
		clock_t end = clock();
		double d = double(end - start) / CLOCKS_PER_SEC;
		cout << "Run time for !1000 = " << " is " << d << " secs" << endl;
	}
}

#endif // 0



/*----------------------------------------------------------------
main
-----------------------------------------------------------------*/
int main() {
  //test_basic();
  //test_addition();
  //test_multiplication();
  //test_factorial();

#if 0
  ulongnum a(9789, verbose);
  ulongnum b("98", verbose);
  ulongnum c('7', verbose);
  cout << "a = " << a << endl;
  cout << "b = " << b << endl;
  cout << "c = " << c << endl;
  //ulongnum sum = a + 78 + b + c;
  ulongnum sum = a + 78 + b + c;
  //cout << "sum = a + 98 + b + c = " << sum << endl;
  cout << "  

	  a + 78 + b + c = " << sum << endl;

#endif 0

  ulongnum a(1234, verbose);
  cout << "a = " << a << endl;
  ulongnum b("4321", verbose);
  cout << "b = " << b << endl;
  ulongnum ans = a * b;
  cout << "ans = " << ans << endl;

  return 0;
}

//EOF

