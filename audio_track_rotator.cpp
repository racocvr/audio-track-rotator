#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <sys/unistd.h>

#include "tvs-api/TVServiceAPI.h"
#include "tvs-api/AVControlProxy.h"

int main( int argc, char *argv[] ) 
{
	IAVControl* pAVControl;
	TVServiceAPI::CreateAVControl(PROFILE_TYPE_MAIN, 0, &pAVControl);
	
	ELanguageCode langCode;
	int audioIndex;
	
	if(pAVControl->GetCurrentAudioInfo(langCode, audioIndex) > 0)
	{		
		if(pAVControl->SetCurrentAudioByIndex(++audioIndex) == 0)
	 	{
			audioIndex = 0;
			
	 		if(pAVControl->SetCurrentAudioByIndex(audioIndex) == 0)
			{
				fprintf(stderr, "SetCurrentAudioByIndex failed\n");
				exit(EXIT_FAILURE);
			}
	 	}
		
		fprintf(stderr, "audio track changed to %d\n", audioIndex);
	}
	else
		fprintf(stderr, "GetCurrentAudioInfo failed\n");

	TVServiceAPI::Destroy();

	exit(EXIT_SUCCESS);
}