//standard header
#include <vector>
#include <utility>
#include "TEfficiency.h"

//test_for_root

void test_for_root_Eff(){

auto C  = new TCanvas("C", "A ratio example");

TFile* pFile = new TFile("folder_new/HGTD_PerformanceStudies_output_old_5.root","update");
//TEfficiency* pEffA = (TEfficiency*)pFile->Get("HGTD_TrkTimePerformanceStudies.AllTracksSelection/HGTD_TrkTimePerformanceStudies.TrackTimeAccToolDefault/m_eff_gt50pcprimes_vs_eta");
TEfficiency* pEffA = (TEfficiency*)pFile->Get("HGTD_TrkTimePerformanceStudies.NoEarlyDecayTracksSelection/HGTD_TrkTimePerformanceStudies.TrackTimeAccTool/m_eff_vs_eta");

TH1* h1A = pEffA->GetCopyPassedHisto();
	
TFile* mFile = new TFile("folder_new/HGTD_PerformanceStudies_output_5.root","update");
//TEfficiency* pEffB = (TEfficiency*)mFile->Get("HGTD_TrkTimePerformanceStudies.AllTracksSelection/HGTD_TrkTimePerformanceStudies.TrackTimeAccToolDefault/m_eff_gt50pcprimes_vs_eta");
TEfficiency* pEffB = (TEfficiency*)mFile->Get("HGTD_TrkTimePerformanceStudies.NoEarlyDecayTracksSelection/HGTD_TrkTimePerformanceStudies.TrackTimeAccTool/m_eff_vs_eta");

TH1* h1B = pEffB->GetCopyPassedHisto();
h1B->SetLineColor(kRed);

auto rp = new TRatioPlot(h1A, h1B);

//Draw and save the graphs
TFile *f = new TFile("histos3.root","RECREATE"); //create a root file 
h1A->Write();
h1B->Write();
rp->Write();


h1A->Draw();
h1B->Draw();
C->SetTicks(0, 1);
rp->Draw();
rp->GetLowYaxis()->SetNdivisions(5);

rp->GetUpperPad()->cd();
TLegend *legend = new TLegend(0.3,0.7,0.7,0.85);
legend->AddEntry("h1A","Old Function","l");
//h1B->SetLineColor(kRed);
legend->AddEntry("h1B","New Function","le");
legend->Draw();

rp->GetLowerRefYaxis()->SetTitle("ratio New/Old");

/*
rp->GetUpperPad()->cd();
TLegend *legend = new TLegend(0.3,0.7,0.7,0.85);
legend->AddEntry("h1","Old","l");
legend->AddEntry("h2","New","le");
legend->Draw(); 
*/

f->Write();  //write histogram in root file
f->Close();

}

//m_eff_vs_eta 
//m_eff_gt50pcprimes_vs_eta
//m_eff_gt50pcprimes_vs_eta_mistag
//m_eff_vs_eta_primesfracAllPrimes
//m_eff_vs_eta_primesfracHalfPrimesHasPrimes
//m_eff_vs_eta_primesfracLessThanHalfPrimes
//m_eff_vs_eta_primesfracMoreThanHalfPrimes
//m_eff_vs_eta_primesfracNoPrimesNoPossiblePrimes
//m_eff_vs_eta_primesfracNoPrimes1PossiblePrimes
//m_eff_vs_eta_primesfracNoPrimes2PossiblePrimes
//m_eff_vs_eta_primesfracNoPrimes3PossiblePrimes
//m_eff_vs_eta_primesfracNoPrimes4PossiblePrimes
