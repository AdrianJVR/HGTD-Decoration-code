//standard header
#include <vector>
#include <utility>
#include "TEfficiency.h"

//test_for_root

void test_for_root_Hist(){

auto C  = new TCanvas("C", "A ratio example");

TFile *f1 = TFile::Open("folder_new/HGTD_PerformanceStudies_output_old_5.root");
TH1D *h1A = (TH1D*)gDirectory->Get("HGTD_TrkTimePerformanceStudies.AllTracksSelection/HGTD_TrkTimePerformanceStudies.TrackTimeAccTool/m_hist_timeres_outlier_casesNoPrimesNoPossiblePrimes");
//TH1D *h1A = (TH1D*)gDirectory->Get("HGTD_TrkTimePerformanceStudies.AllTracksSelection/HGTD_TrkTimePerformanceStudies.TrackTimeAccTool/m_hist_timeres_outlier_cas");
h1A->SetLineColor(kBlue);

TFile *f2 = TFile::Open("folder_new/HGTD_PerformanceStudies_output_5.root");
TH1D *h1B = (TH1D*)gDirectory->Get("HGTD_TrkTimePerformanceStudies.AllTracksSelection/HGTD_TrkTimePerformanceStudies.TrackTimeAccTool/m_hist_timeres_outlier_casesNoPrimesNoPossiblePrimes");
//TH1D *h1B = (TH1D*)gDirectory->Get("HGTD_TrkTimePerformanceStudies.AllTracksSelection/HGTD_TrkTimePerformanceStudies.TrackTimeAccTool/m_hist_timeres_outlier_cas");
h1B->SetLineColor(kRed);

auto rp = new TRatioPlot(h1A, h1B);

//Draw and save the graphs

TFile *f = new TFile("histos3.root","RECREATE"); //create a root file 
h1A->Write();
h1B->Write();
rp->Write();


h1A->Draw();
h1B->Draw();

//C->SetTicks(0, 1);
rp->Draw();
rp->GetLowYaxis()->SetNdivisions(10);
rp->GetLowerRefYaxis()->SetTitle("ratio New/Old");

rp->GetUpperPad()->cd();
TLegend *legend = new TLegend(0.3,0.7,0.7,0.85);
legend->AddEntry("h1A","Old Function","l");
//h1B->SetLineColor(kRed);
legend->AddEntry("h1B","New Function","le");
legend->Draw();

f->Write();  //write histogram in root file
f->Close();

}

// pt
// \eta\
// \phi\
// m_hist_timeres_outlier_casesAllPrimes
// m_hist_timeres_outlier_casesHalfPrimesHasPrimes
// m_hist_timeres_outlier_casesLessThanHalfPrimes
// m_hist_timeres_outlier_casesMoreThanHalfPrimes
// m_hist_timeres_outlier_casesNoPrimesNoPossiblePrimes
// m_hist_timeres_outlier_casesNoPrimes1PossiblePrimes
// m_hist_timeres_outlier_casesNoPrimes2PossiblePrimes
// m_hist_timeres_outlier_casesNoPrimes3PossiblePrimes
// m_hist_timeres_outlier_cas
