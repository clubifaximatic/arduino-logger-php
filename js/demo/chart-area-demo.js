// Set new default font family and font color to mimic Bootstrap's default styling
Chart.defaults.global.defaultFontFamily = 'Nunito', '-apple-system,system-ui,BlinkMacSystemFont,"Segoe UI",Roboto,"Helvetica Neue",Arial,sans-serif';
Chart.defaults.global.defaultFontColor = '#858796';

// function number_format(number, decimals, dec_point, thousands_sep) {
//   // *     example: number_format(1234.56, 2, ',', ' ');
//   // *     return: '1 234,56'
//   number = (number + '').replace(',', '').replace(' ', '');
//   var n = !isFinite(+number) ? 0 : +number,
//     prec = !isFinite(+decimals) ? 0 : Math.abs(decimals),
//     sep = (typeof thousands_sep === 'undefined') ? ',' : thousands_sep,
//     dec = (typeof dec_point === 'undefined') ? '.' : dec_point,
//     s = '',
//     toFixedFix = function(n, prec) {
//       var k = Math.pow(10, prec);
//       return '' + Math.round(n * k) / k;
//     };
//   // Fix for IE parseFloat(0.55).toFixed(0) = 0;
//   s = (prec ? toFixedFix(n, prec) : '' + Math.round(n)).split('.');
//   if (s[0].length > 3) {
//     s[0] = s[0].replace(/\B(?=(?:\d{3})+(?!\d))/g, sep);
//   }
//   if ((s[1] || '').length < prec) {
//     s[1] = s[1] || '';
//     s[1] += new Array(prec - s[1].length + 1).join('0');
//   }
//   return s.join(dec);
// }

d3.csv('https://bideko.elllimoner.com/index.php/sample/fetch?since=2023-03-21 06:40')
  .then(makeChart);

function makeChart(samples) {
  var ctxCO2 = document.getElementById("chartCO2");
  var ctxO2 = document.getElementById("chartO2");

  const colors = ['#4e73df', '#1cc88a', '#36b9cc', '#f6c23e', '#e74a3b', '#858796' ]
  const theLabels = samples.map(function(d) {return d.timestamp});

  const co2_1 = samples.map(function(d) {return d.CO2_1});
  const co2_2 = samples.map(function(d) {return d.CO2_2});
  const co2_3 = samples.map(function(d) {return Number(d.CO2_3)});
  const co2_4 = samples.map(function(d) {return d.CO2_4});
  const co2_5 = samples.map(function(d) {return d.CO2_5});
  const co2_6 = samples.map(function(d) {return d.CO2_6});

  var chart = new Chart(ctxCO2, {
    type: 'line',
    data: {
      labels: theLabels,
      datasets: [
        {
          label: "CO2_1",
          tension: 0.4,
          fill: false,
          borderColor: colors[0],
          data: co2_1
        },
        {
          label: "CO2_2",
          tension: 0.4,
          fill: false,
          borderColor: colors[1],
          data: co2_2
        },
        {
          label: "CO2_3",
          tension: 0.4,
          fill: false,
          borderColor: colors[2],
          data: co2_3
        },
        {
          label: "CO2_4",
          tension: 0.4,
          fill: false,
          borderColor: colors[3],
          data: co2_4
        },
        {
          label: "CO2_5",
          tension: 0.4,
          fill: false,
          borderColor: colors[4],
          data: co2_5
        },
        {
          label: "CO2_6",
          tension: 0.4,
          fill: false,
          borderColor: colors[5],
          data: co2_6
        },
      ]
    }
  });

  const o2_1 = samples.map(function(d) {return d.O2_1});
  const o2_2 = samples.map(function(d) {return d.O2_2});
  const o2_3 = samples.map(function(d) {return d.O2_3});
  const o2_4 = samples.map(function(d) {return d.O2_4});
  const o2_5 = samples.map(function(d) {return d.O2_5});
  const o2_6 = samples.map(function(d) {return d.O2_6});

  var chart = new Chart(ctxO2, {
    type: 'line',
    data: {
      labels: theLabels,
      datasets: [
        {
          label: "O2_1",
          tension: 0.4,
          fill: false,
          borderColor: colors[0],
          data: o2_1
        },
        {
          label: "O2_2",
          tension: 0.4,
          fill: false,
          borderColor: colors[1],
          data: o2_2
        },
        {
          label: "O2_3",
          tension: 0.4,
          fill: false,
          borderColor: colors[2],
          data: o2_3
        },
        {
          label: "O2_4",
          tension: 0.4,
          fill: false,
          borderColor: colors[3],
          data: o2_4
        },
        {
          label: "O2_5",
          tension: 0.4,
          fill: false,
          borderColor: colors[4],
          data: o2_5
        },
        {
          label: "O2_6",
          tension: 0.4,
          fill: false,
          borderColor: colors[5],
          data: o2_6
        },
      ]
    }
  });
}

// Area Chart Example
// var ctx = document.getElementById("myAreaChart");
// var myLineChart = new Chart(ctx, {
//   type: 'line',
//   data: {
//     labels: ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"],
//     datasets: [{
//       label: "Earnings",
//       lineTension: 0.3,
//       backgroundColor: "rgba(78, 115, 223, 0.05)",
//       borderColor: "rgba(78, 115, 223, 1)",
//       pointRadius: 3,
//       pointBackgroundColor: "rgba(78, 115, 223, 1)",
//       pointBorderColor: "rgba(78, 115, 223, 1)",
//       pointHoverRadius: 3,
//       pointHoverBackgroundColor: "rgba(78, 115, 223, 1)",
//       pointHoverBorderColor: "rgba(78, 115, 223, 1)",
//       pointHitRadius: 10,
//       pointBorderWidth: 2,
//       data: [0, 10000, 5000, 15000, 10000, 20000, 15000, 25000, 20000, 30000, 25000, 40000],
//     }],
//   },
//   options: {
//     maintainAspectRatio: false,
//     layout: {
//       padding: {
//         left: 10,
//         right: 25,
//         top: 25,
//         bottom: 0
//       }
//     },
//     scales: {
//       xAxes: [{
//         time: {
//           unit: 'date'
//         },
//         gridLines: {
//           display: false,
//           drawBorder: false
//         },
//         ticks: {
//           maxTicksLimit: 7
//         }
//       }],
//       yAxes: [{
//         ticks: {
//           maxTicksLimit: 5,
//           padding: 10,
//           // Include a dollar sign in the ticks
//           callback: function(value, index, values) {
//             return '$' + number_format(value);
//           }
//         },
//         gridLines: {
//           color: "rgb(234, 236, 244)",
//           zeroLineColor: "rgb(234, 236, 244)",
//           drawBorder: false,
//           borderDash: [2],
//           zeroLineBorderDash: [2]
//         }
//       }],
//     },
//     legend: {
//       display: false
//     },
//     tooltips: {
//       backgroundColor: "rgb(255,255,255)",
//       bodyFontColor: "#858796",
//       titleMarginBottom: 10,
//       titleFontColor: '#6e707e',
//       titleFontSize: 14,
//       borderColor: '#dddfeb',
//       borderWidth: 1,
//       xPadding: 15,
//       yPadding: 15,
//       displayColors: false,
//       intersect: false,
//       mode: 'index',
//       caretPadding: 10,
//       callbacks: {
//         label: function(tooltipItem, chart) {
//           var datasetLabel = chart.datasets[tooltipItem.datasetIndex].label || '';
//           return datasetLabel + ': $' + number_format(tooltipItem.yLabel);
//         }
//       }
//     }
//   }
// });
