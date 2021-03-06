void normalize(TH1D* hist);

void DrawOnTop(TString file1, TString file2)
{
	TFile* f = new TFile(file1,"read");
	f->cd("dtSpect");
	TH1D* dtSpect1 = (TH1D*)gDirectory->Get("Drifttime spectrum");
	f->cd("rtRelation");
	TH1D* rtRel1 = (TH1D*)gDirectory->Get("rt-relation");
	cout << rtRel1 << endl;

	TFile* f2 = new TFile(file2,"read");
	f2->cd("dtSpect");
	TH1D* dtSpect2 = (TH1D*)gDirectory->Get("Drifttime spectrum");
	f2->cd("rtRelation");
	TH1D* rtRel2 = (TH1D*)gDirectory->Get("rt-relation");
	cout << rtRel2 << endl;

	normalize(dtSpect1);
	normalize(dtSpect2);

	dtSpect1->SetLineColor(kBlue);
	dtSpect2->SetLineColor(kRed);
	rtRel1->SetLineColor(kBlue);
	rtRel2->SetLineColor(kRed);

	TLegend* legend = new TLegend(0.1,0.7,0.48,0.9);
	legend->SetHeader("Histograms");
	legend->AddEntry(rtRel1,"Ar:CO2 80:20","l");
	legend->AddEntry(rtRel2,"Ar:CO2:N2 96:3:1","l");

	rtRel1->Draw("hist");
	rtRel2->Draw("same");
	legend->Draw("same");
}

void normalize(TH1D* hist)
{
	hist->Scale(1/(hist->Integral()));
}
