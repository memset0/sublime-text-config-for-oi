// Execute & Pause
// Runs a program, then keeps the console window open after it finishes

#include <string>
#include <cstdio>
#include <cstdint>
#include <chrono>
using std::string;

#define MAX_COMMAND_LENGTH 32768
#define MAX_ERROR_LENGTH 2048

uint64_t GetClockTick() {
	uint64_t clock = std::chrono::steady_clock::now().time_since_epoch().count();
	return clock;
}

uint64_t GetClockFrequency() {
	return 1000000000;
}

void PauseExit(int exitcode) {
	system("read -n 1");
	exit(exitcode);
}

string GetCommand(int argc,char** argv) {
	string result;
	for(int i = 1;i < argc;i++) {
		// Quote the first argument in case the path name contains spaces
//		if(i == 1) {
//			result += string("\"") + string(argv[i]) + string("\"");
//		} else {
			result += string(argv[i]);
//		}
		
		// Add a space except for the last argument
		if(i != (argc-1)) {
			result += string(" ");
		}
	}
	
	if(result.length() > MAX_COMMAND_LENGTH) {
		printf("\n--------------------------------");
		printf("\nError: Length of command line string is over %d characters\n",MAX_COMMAND_LENGTH);
		PauseExit(EXIT_FAILURE);
	}
	
	return result;
}

uint32_t ExecuteCommand(string& command) {
	system(command.c_str());
	return 0;

	// STARTUPINFO si;
	// PROCESS_INFORMATION pi;
	// memset(&si,0,sizeof(si));
	// si.cb = sizeof(si);
	// memset(&pi,0,sizeof(pi));
	
	// if(!CreateProcess(NULL, (LPSTR)command.c_str(), NULL, NULL, false, 0, NULL, NULL, &si, &pi)) {
	// 	printf("\n--------------------------------");
	// 	printf("\nFailed to execute \"%s\":",command.c_str());
	// 	PauseExit(EXIT_FAILURE);
	// }
	// WaitForSingleObject(pi.hProcess, INFINITE); // Wait for it to finish
	
	// uint32_t result = 0;
	// GetExitCodeProcess(pi.hProcess, &result);
	// return result;
}

int main(int argc, char** argv) {
	
	// First make sure we aren't going to read nonexistent arrays
	if(argc < 2) {
		printf("\n--------------------------------");
		printf("\nUsage: ConsolePauser.exe <filename> <parameters>\n");
		PauseExit(EXIT_SUCCESS);
	}
	
	// Then build the to-run application command
	string command = GetCommand(argc,argv);
	
	// Save starting timestamp
	uint64_t starttime = GetClockTick();
	
	// Then execute said command
	uint32_t returnvalue = ExecuteCommand(command);
	
	// Get ending timestamp
	uint64_t endtime = GetClockTick();
	double seconds = (endtime - starttime) / (double)GetClockFrequency();

	// Done? Print return value of executed program
	printf("\n--------------------------------");
	printf("\nProcess exited after %.4g seconds with return value %u\n", seconds, returnvalue);
	PauseExit(EXIT_SUCCESS);
}
