//help taken from https://metacpan.org/pod/Chart::Gnuplot
//also help (but mostly just sass) from https://stackoverflow.com/questions/6350430/histograms-in-chartgnuplot-perl-is-it-possible




use Chart::Gnuplot;

open (FH, $ARGV[0])
	|| die "error opening!";
read(FH, $x, 99999);

$argNum = @ARGV;

@args = ();
@freq = ();

for (my $n=1; $n < $numArgs; $n++){
	
	my @x = $ARGV[$i];
	push @args, @x =~ /@d/g; //global
	my $count = @c;

	push @freq, $count; 
}

my $chart = Chart::Gnuplot->new(
    output => "chart.jpg",
    terminal => "jpeg",
    title  => "Freq. of words in file",
    xlabel => "Words",
    ylabel => "Freq. in file"
	
);

my $dataSet = Chart::Gnuplot::DataSet->new(
    xdata => \@args,
    ydata => \@freq,
    style => "histogram",
    using => "2:xticlabels(1)",
);


print "Content-type: text/html\n\n";
print "<html><center><head>\n";
print "<title>Gnuplot image</title><h1><font size=\"16\" color=\"red\">CS 410 Webserver</font></h1>\n";
print "</head><body>\n";
print "<img src=\"chart.jpg\">\n";
print "</body></center></html>\n";