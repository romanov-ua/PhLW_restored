// Fill out your copyright notice in the Description page of Project Settings.


#include "NormalDistribution.h"
#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"

float UNormalDistribution::MarsagliaPolarMethod(const float mathExpct, const float stdDev) {

    static double spare;
    static bool hasSpare = false;

    if (hasSpare) {
        hasSpare = false;
        return spare * stdDev + mathExpct;
    }
    else {
        double u, v, s;
        do {
            u = (rand() / ((double)RAND_MAX)) * 2.0 - 1.0;
            v = (rand() / ((double)RAND_MAX)) * 2.0 - 1.0;
            s = u * u + v * v;
        } while (s >= 1.0 || s == 0.0);
        s = sqrt(-2.0 * log(s) / s);
        spare = v * s;
        hasSpare = true;
        return mathExpct + stdDev * u * s;
    }

}

bool UNormalDistribution::ExportStringArray(FString ExportDirectory, FString Filename, TArray<FString> StringArray, bool AllowOverWriting = true) 
{
    ExportDirectory += "\\";
    ExportDirectory += Filename;
    if (!AllowOverWriting) {
        if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*ExportDirectory)) 
        {
            return false;
        }

    }

    FString FinalString = "";
    for (FString& Each : StringArray)
    {
        FinalString += Each;
        FinalString += LINE_TERMINATOR;
    }

    return FFileHelper::SaveStringToFile(FinalString, *ExportDirectory);
}
